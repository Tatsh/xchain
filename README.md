Based on [original documentation by OpenTTD team](http://devs.openttd.org/~truebrain/compile-farm/apple-darwin9.txt).

With these files you may build odcctools and GCC 4.2.1 targetting Darwin/macOS.

This has been tested in the following environments:

* *x86_64-pc-linux-gnu* with GCC 4.5.3

The following targets have been tested:

* *i686-apple-darwin11*
* *x86_64-apple-darwin11*
* *arm-apple-darwin* (requires iOS SDK)

These might work:

* *ppc-apple-darwin11*
* *ppc64-apple-darwin11*

Decide your target, and export:

```bash
export TARGET=i686-apple-darwin11
```

11 denotes Lion, 10 for Snow Leopard, and 9 for Leopard. These are mostly superficial. All code will run on 10.5 and greater.

Decide your prefix directory and set it to a variable.

```bash
export PREFIX=/usr/$TARGET
mkdir $PREFIX
cd $PREFIX
```

In `~/.bashrc` or similar you may want:

```bash
export DARWIN_PREFIX=<prefix you chose>
```

# Prepare your prefix

If you don't have a Mac, skip this and read *Prepare your prefix (no Mac)*. Even if you have a Mac, the no-Mac method is cleaner than using scp but not as easy.

You will need a copy of an SDK directory to begin. You can choose any version past 10.4u really but I suppose only if you need new things in Lion would copy Lion's SDK (and that requires Lion itself of course). I expect that you are doing most development on the Mac anyway so therefore your compiler settings in Xcode will decide support level.

```bash
mkdir $PREFIX/SDKs
cd $PREFIX/SDKs
```

If you have Snow Leopard:

```bash
export SDK=MacOSX10.6.sdk
scp -r myname@mymac:/Developer/SDKs/$SDK .
```

If you have Lion (and want latest headers):

```bash
export SDK=MacOSX10.7.sdk
scp -r myname@mymac:/Developer/SDKs/$SDK .
```

# Prepare your prefix (no Mac)

If you are copying from Mac with scp, skip to 'Continue with scp'.

Download the DMG from Apple for Xcode, any version. You need to have the following:

* Linux kernel built with HFS+ file system driver
* Catacombae DMGExtractor (requires Java) http://sourceforge.net/projects/catacombae/
  * Gentoo users: I have an ebuild and prefix: https://github.com/tatsh/tatsh-overlay and once installed, simply run: `emerge app-arch/dmgextractor` to get this
* p7zip
* xar
* cpio

Use `mount` and `umount` as root or with `sudo` (probably easier with `sudo`). Example here is with Xcode 4.2. Replace `/mnt/tmp` with your own mount point.

```bash
cd where-my-xcode-dmg-lives
java -jar path/to/dmgextractor.jar xcode_4.2_and_ios_5_sdk_for_snow_leopard.dmg my.iso (click OK on any prompts)
# if on Gentoo, you can use `dmgextractor xcode_4.2_and_ios_5_sdk_for_snow_leopard.dmg` my.iso
7z x my.iso
mount -t hfsplus disk\ image.hfs /mnt/tmp
xar -f /mnt/tmp/Packages/MacOSX10.6.pkg Payload
cpio -i < Payload
umount /mnt/tmp
```

You will now have an SDKs directory, but it needs fixing.

```bash
cd SDKs/MacOSX10.6.sdk
rm Library/Frameworks
ln -s System/Library/Frameworks Library
mv Developer/usr/llvm-gcc-4.2 usr
rm -r Developer/usr
ln -s usr Developer
```

Copy the prefix:

```bash
cd ../..
cp -r SDKs $PREFIX

cd $PREFIX
```

Note that we are going to put stuff in this .sdk directory. Anything we build from here will be placed inside. So we are going to create symlinks to its directories in $PREFIX.

```bash
ln -s SDKs/$SDK/Developer
ln -s SDKs/$SDK/Library
ln -s SDKs/$SDK/System
ln -s SDKs/$SDK/usr
```

If you used the no-Mac method, skip to *Building cctools'*.

# Continue with scp

Delete any of YOUR frameworks (these are all from 3rd parties, not Apple). None of these are necessary.

```bash
rm -R Library/Frameworks
```

Create a symlink to the Apple Frameworks directory.

```bash
cd Library
ln -s ../System/Library/Frameworks
cd ..
```

Later on, you can copy the 3rd party frameworks from your Mac to $PREFIX/Library/Frameworks:

```bash
scp -r /Developer/SDKs/MacOSX10.6.sdk/Library/Frameworks/* $PREFIX/Library/Frameworks
```

`usr` is of great importantance to us in the next steps. It's where cctools and GCC will go. So yes, this `usr` directory (and possibly `Library`) will eventually be 'dirty' and non-equivalent to the one in macOS (and in the next steps we will overwrite files in the directory).

Never copy the SDK directory back to macOS for any reason.

# Building cctools

You really should only apply the patch if you are not on macOS/Darwin, because I have not tested any of this on OS X/Darwin yet.

```bash
wget http://opensource.apple.com/tarballs/cctools/cctools-806.tar.gz
tar xvf cctools-806.tar.gz
patch -p0 < patches/cctools-806-nondarwin.patch
cd cctools-806
chmod +x configure
CFLAGS="-m32" LDFLAGS="-m32" ./configure --prefix=$PREFIX/usr --target=$TARGET --with-sysroot=$PREFIX
make
make install
cd ..
```

Note `-m32`. Everything will be 32-bit. Building for 64-bit is not supported (but using 32-bit to build 64-bit binaries is). Do not try optimisation flags. `ranlib` is especially sensitive.

Ignore ALL warnings. There will be many (or you can use `-w` for a `CFLAG`).

# Building ld64

To build GCC we cannot use what's known as 'classic' `ld`. We have to use `ld64` (even though we are not going to build it in 64-bit mode). For the moment, use odcctools-9.2 from the iphone-dev project (the version in this repository is patched for GCC 4.5):

```bash
cd odcctools-9.2-ld
CFLAGS="-m32" LDFLAGS="-m32" ./configure \
    --prefix=$PREFIX/usr \
    --target=$TARGET \
    --with-sysroot=$PREFIX \
    --enable-ld64
make
cd ld64
make install
cd ../..
```

Do not try optimisation flags here either.

Set `$PATH` to have your new tools. You may want to add this to your `~/.bashrc` or similar.

```bash
export PATH="$PATH:/usr/$TARGET/usr/bin"
```

# Building GCC

Now you can proceed to build GCC, but it must be patched first. Patches are located in `patches`.

```bash
wget http://opensource.apple.com/tarballs/gcc/gcc-5666.3.tar.gz
tar xvf gcc-5666.3.tar.gz
cd gcc-5666.3
patch -p1 < ../patches/gcc-5666.3-cflags.patch
```

Apply if you are annoyed by the default directory structure:

```bash
patch -p1 < ../patches/gcc-5666.3-tooldir.patch
```

After patching, I recommend building outside of the source of GCC.

```bash
cd ..
mkdir gcc-build
cd gcc-build

CFLAGS="-m32" CXXFLAGS="$CFLAGS" LDFLAGS="-m32" \
    ../gcc-5666.3/configure --prefix=$PREFIX/usr \
    --disable-checking \
    --enable-languages=c,objc,c++,obj-c++ \
    --with-as=$PREFIX/usr/bin/$TARGET-as \
    --with-ld=$PREFIX/usr/bin/$TARGET-ld64 \
    --target=$TARGET \
    --with-sysroot=$PREFIX \
    --enable-static \
    --enable-shared \
    --enable-nls \
    --disable-multilib \
    --disable-werror \
    --enable-libgomp \
    --with-gxx-include-dir=$PREFIX/usr/include/c++/4.2.1 \
    --with-ranlib=$PREFIX/usr/bin/$TARGET-ranlib \
    --with-lipo=$PREFIX/usr/bin/$TARGET-lipo
```

Optimisations do work here (most of the time). You can try to configure with:

```bash
CFLAGS="-m32 -O2 -msse2"
```

No, there is no Java (GCJ) or Fortran.

Make and install like normal.

```bash
make
make install
```

Sometimes you may get an issue about ranlib not working or lipo, which is why `--with-ranlib` and `--with-lipo` are appended to `./configure`. However, you may have to run `make` again or not use a `-j` flag. I would recommend not using the `-j` flag anyway just to ease debugging of any issues. Seriously, try doing `make` over and over until it does work.

If `ranlib` has a buffer overflow during build, it is probably because you enabled optimisation flags.

# Hack to fix include path

```bash
export LAST=$PWD
cd $PREFIX/usr/local
ln -s ../lib/gcc/$TARGET/4.2.1/include
cd $LAST
```

# Test GCC

From the cloned source:

```bash
$TARGET-gcc -o msg msg.m \
    -fconstant-string-class=NSConstantString \
    -lobjc -framework Foundation
```

Test C++:

```bash
$TARGET-g++ -o msgcpp msg.cpp -I$PREFIX/usr/include/c++/4.2.1
```

I know, that's a weird `-I` flag. For now, just use an alias for `$TARGET-g++` with it. You can safely alias `$TARGET-gcc` as well with `-fconstant-string-class=NSConstantString` even if you are compiling C.

```bash
file msg
```

Output:

    msg: Mach-O executable i386

Copying to Mac and executing with ssh:

```bash
scp msg myname@mymac:
ssh myname@mymac ./msg
scp msgcpp myname@mymac:
ssh myname@mymac ./msgcpp
```

Output:

    2011-09-03 03:51:52.887 msg[31266:1007] Are you John smith?
    2011-09-03 03:51:52.889 msg[31266:1007] My message
    This was compiled on a non-Mac!

# Optional: Building LLVM-GCC

Because LLVM is the future right?

First, force the use of ld64 everywhere (yes you can keep this as permanent):

```bash
export LAST=$PWD
cd $PREFIX/usr/bin
mv $TARGET-ld $TARGET-ld.classic
ln -s $TARGET-ld64 $TARGET-ld
cd $LAST
```

You need to build Apple's LLVM first.

```bash
wget http://opensource.apple.com/tarballs/llvmgcc42/llvmgcc42-2335.15.tar.gz
tar xvf llvmgcc42-2335.15.tar.gz
mkdir llvm-obj
cd llvm-obj
CFLAGS="-m32" CXXFLAGS="$CFLAGS" LDFLAGS="-m32" \
    ../llvmgcc42-2335.15/llvmCore/configure \
    --prefix=$PREFIX/usr \
    --enable-optimized \
    --disable-assertions \
    --target=$TARGET
make
make install # optional
cd ..
```

This is somewhat intensive (lots of C++) so if you don't have a powerful PC do not use `-j` flag with `make`.

Next, proceed to build GCC itself, but you need to patch one thing (at least needed GCC 4.5):

```bash
cd llvmgcc42-2335.15
patch -p0 < ../patches/llvmgcc42-2335.15-redundant.patch
patch -p0 < ../patches/llvmgcc42-2335.15-mempcpy.patch
cd ..
```

Build outside the directory.

```bash
mkdir llvmgcc-build
cd llvmgcc-build
CFLAGS="-m32" CXXFLAGS="$CFLAGS" LDFLAGS="-m32" \
    ../llvmgcc42-2335.15/configure \
    --target=$TARGET \
    --with-sysroot=$PREFIX \
    --prefix=$PREFIX/usr \
    --enable-languages=objc,c++,obj-c++ \
    --disable-bootstrap \
    --enable--checking \
    --enable-llvm=$PWD/../llvm-obj \
    --enable-shared \
    --enable-static \
    --enable-libgomp \
    --disable-werror \
    --disable-multilib \
    --program-transform-name=/^[cg][^.-]*$/s/$/-4.2/ \
    --with-gxx-include-dir=$PREFIX/usr/include/c++/4.2.1 \
    --program-prefix=$TARGET-llvm- \
    --with-slibdir=$PREFIX/usr/lib \
    --with-ld=$PREFIX/usr/bin/$TARGET-ld64 \
    --with-tune=generic \
    --with-as=$PREFIX/usr/bin/$TARGET-as \
    --with-ranlib=$PREFIX/usr/bin/$TARGET-ranlib \
    --with-lipo=$PREFIX/usr/bin/$TARGET-lipo
make
make install
```

Test:

```bash
export LAST=$PWD
cd $PREFIX/usr/bin
ln -s $TARGET-as as
cd $LAST
cd ..
PATH="$PREFIX/usr/bin" $TARGET-llvm-gcc -o msg msg.m \
    -fconstant-string-class=NSConstantString \
    -lobjc -framework Foundation
PATH="$PREFIX/usr/bin" $TARGET-llvm-g++ -o msgcpp msg.cpp \
    -I$PREFIX/usr/include/c++/4.2.1
```

I know, yet again C++ paths fail to work.

Ignore all warnings.

# Distcc

Distcc for Gentoo (not for Objective-C or C++ yet due to default argument issues):
Follow these instructions:

* [Gentoo Distcc Guide](http://www.gentoo.org/doc/en/distcc.xml)
* [Gentoo Cross-compiling with Distcc Guide](http://www.gentoo.org/doc/en/cross-compiling-distcc.xml) (with your target being macOS Prefix)

# What works for me

* `CFLAGS="-O2 -msse2 -pipe -m32"` for building llvm-GCC and regular GCC
* `make -j3` works for everything for me

# iPhone

This is with a default install of Xcode 4.1.1 from the Mac App Store. You can also try the non-Mac method to get the equivalent file.

Follow the above instructions but rather than 10.7 or 10.6 SDK, copy the iOS 4.3 SDK:

```bash
scp -r myname@mymac:/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.3.sdk .
export TARGET="arm-apple-darwin"
export PREFIX="/usr/$TARGET"
```

Build cctools and ld64. Do not build GCC. Instead build LLVM as described above.

cctools for Gentoo the easy way (as root, example amd64 architecture):

```bash
export OVERLAY="/usr/tatsh-overlay" # or where you want it
git clone git://github.com/tatsh/tatsh-overlay.git $OVERLAY
echo "$PORTDIR_OVERLAY=\"\$PORTDIR_OVERLAY $OVERLAY\"" >> /etc/make.conf
eix-update # optional, only if you have eix installed
echo 'cross-arm-apple-darwin/cctools ~amd64' >> /etc/portage/package.keywords
emerge cross-arm-apple-darwin/cctools
```

The difference comes in building LLVM GCC. Use LLVM-GCC from Apple's site, apply the patches as described, but build with the following arguments to `./configure` (note lack of `-m32`):

```bash
../llvmgcc42-2335.15/configure \
    --target=$TARGET \
    --with-sysroot=$PREFIX \
    --prefix=$PREFIX/usr \
    --enable-languages=objc,c++,obj-c++ \
    --disable-bootstrap \
    --enable--checking \
    --enable-llvm=$PWD/../llvm-obj \
    --enable-shared \
    --enable-static \
    --enable-libgomp \
    --disable-werror \
    --disable-multilib \
    --program-transform-name=/^[cg][^.-]*$/s/$/-4.2/ \
    --with-gxx-include-dir=$PREFIX/usr/include/c++/4.2.1 \
    --program-prefix=$TARGET-llvm- \
    --with-slibdir=$PREFIX/usr/lib \
    --with-ld=$PREFIX/usr/bin/$TARGET-ld64 \
    --with-as=$PREFIX/usr/bin/$TARGET-as \
    --with-ranlib=$PREFIX/usr/bin/$TARGET-ranlib \
    --with-lipo=$PREFIX/usr/bin/$TARGET-lipo \
    --enable-sjlj-exceptions
make
make install
```

This will fix g++:

```bash
cd $PREFIX/usr/lib
ln -s libgcc_s.1.dylib libgcc_s.10.4.dylib
```

This will make it a little more sane:

```bash
cd $PREFIX/usr/bin
ln -s arm-apple-darwin-gcc-4.2.1 arm-apple-darwin-gcc
ln -s arm-apple-darwin-g++-4.2.1 arm-apple-darwin-g++
```

You will have a working compiler targetting iOS. You need a jailbroken phone before any code will run.

Try:

```bash
ssh root@My_iPhone uname -a
arm-apple-darwin-g++ -o msg.arm msg.cpp \
    -I$PREFIX/usr/include/c++/4.2.1 \
    -I$PREFIX/usr/include/c++/4.2.1/armv6-apple-darwin10
scp msg.arm root@My_iPhone:
ssh root@My_iPhone ./msg.arm
```

Output:

    Darwin My_iPhone 11.0.0 Darwin Kernel Version 11.0.0: Wed Mar 30 18:51:10 PDT 2011; root:xnu-1735.46~10/RELEASE_ARM_S5L8930X iPhone3,1 arm N90AP Darwin
    This was compiled on a non-Mac!

Note that you need both of those include path arguments. Yes, it's an ongoing issue.

Also note that the minimum version to run any code is iOS 3.0 by default. To get 2.0 support for example, use `-miphoneos-version-min=2.0` in your line:

```bash
arm-apple-darwin-g++ -o msg.o -c msg.cpp \
    -I$PREFIX/usr/include/c++/4.2.1 \
    -I$PREFIX/usr/include/c++/4.2.1/armv6-apple-darwin10 \
    -miphoneos-version-min=2.0
```

Also note that these are not univeral binaries, even if you use `-force_cpusubtype_ALL`. These are armv6.

# Generate fat binary

Compile both architectures:

```bash
export TARGET=x86_64-apple-darwin11
$TARGET-g++ -o msg.x86_64 -I$PREFIX/usr/include/c++/4.2.1
export TARGET=arm-apple-darwin
$TARGET-g++ -o msg.arm \
    -I$PREFIX/usr/include/c++/4.2.1 \
    -I$PREFIX/usr/include/c++/4.2.1/armv6-apple-darwin10
```

Now use lipo from any of the architectures you have built:

```bash
$TARGET-lipo x86_64-apple-darwin11-lipo -create -arch arm msg.arm -arch x86_64 msg.x86_64 -output msg
```

Testing on iPhone:

```bash
scp msg root@My_iPhone:
ssh root@My_iPhone ./msg
```

Output:

    This was compiled on a non-Mac!

Get info from a mac:

```bash
scp msg myname@mymac
ssh myname@mymac lipo -detailed_info msg
```

Output:

    Fat header in: msg
    fat_magic 0xcafebabe
    nfat_arch 2
    architecture arm
        cputype CPU_TYPE_ARM
        cpusubtype CPU_SUBTYPE_ARM_ALL
        offset 4096
        size 13052
        align 2^12 (4096)
    architecture x86_64
        cputype CPU_TYPE_X86_64
        cpusubtype CPU_SUBTYPE_X86_64_ALL
        offset 20480
        size 9288
        align 2^12 (4096)

# To-do list

* Fix paths when invoked (sysroot issue, maybe `--with-gxx-include-dir` will fix):
  * Double search paths for C++: `$PREFIX/x86_64-apple-darwin11:$PREFIX/x86_64-apple-darwin11/$PREFIX/x86_64-apple-darwin11/include/c++/4.2.1/x86_64-apple-darwin11`
* `ld` warnings about arch maybe
* distcc for Objective-C and C++
* distcc with MacPorts
* Get latest cctools to build on Linux (DONE except for cbtlibs, efitools, gprof; these are probably unnecessary)
* Clang
* HOWTO generate `.app` directory, plist, Resources, etc (nib files and CoreData impossible without Mac?)
