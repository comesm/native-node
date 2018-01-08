#include <nan.h>

using namespace v8;

 NAN_METHOD(Length) {
  // int i = 3;
  // int *pi = &i; //= &i;

  // int &ri = i;

  // printf("%p\n", (void *)pi);
  // printf("%p\n", pi);
  //printf(i.t + "\n");


   Nan::MaybeLocal<String> maybeStr = Nan::To<String>(info[0]);
   Nan::HandleScope scope;
   v8::Local<String> str;


    if(maybeStr.ToLocal(&str) == false) {
     Nan::ThrowError("Error converting first argument to string");
    }

  int len = strlen(*String::Utf8Value(str));
  printf("%i\n", len);
  info.GetReturnValue().Set(len);
   //printf("%s\n", *str);
   //foo = &str


}



NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New("length").ToLocalChecked(),
      Nan::GetFunction(Nan::New<FunctionTemplate>(Length)).ToLocalChecked());
}

NODE_MODULE(myaddon, Init)