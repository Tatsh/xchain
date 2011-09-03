/* APPLE LOCAL file radar 4567449 */
/* Sibcall outgoing arguments were being written over incoming arguments
   before the incoming arguments were being read, when the incoming args
   were partially in registers and partially on the stack.  */

int result;

typedef struct {
  int a;
  int b;
  int c;
  int d;
} s32_t;

void func2(int i, int j, s32_t s32) {
  result = s32.a + s32.b + s32.c + s32.d;
}

void func1(int i, int j, int k, s32_t s32) {
  func2(i, j, s32);
}

int main(int argc, const char *argv[]) {
  s32_t s32 = { 1, 2, 3, 4 };

  func1 (20, 30, 40, s32);
  return (result - 10);
}

