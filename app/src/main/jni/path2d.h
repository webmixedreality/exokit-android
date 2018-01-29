#ifndef PATH2D_H_
#define PATH2D_H_

#include <v8.h>
#include <nan/nan.h>
#include <Context.h>
#include <Image.h>
#include <ImageData.h>
#include <Point.h>
#include <Path2D.h>

using namespace v8;
using namespace node;

#define JS_STR(...) Nan::New<v8::String>(__VA_ARGS__).ToLocalChecked()
#define JS_INT(val) Nan::New<v8::Integer>(val)
#define JS_FLOAT(val) Nan::New<v8::Number>(val)
#define JS_BOOL(val) Nan::New<v8::Boolean>(val)

class Path2D : public ObjectWrap {
public:
  static Handle<Object> Initialize(Isolate *isolate);
  void MoveTo(double x, double y);
  void LineTo(double x, double y);
  void ClosePath();
  void Arc(double x, double y, double radius, double startAngle, double endAngle, double anticlockwise);
  void ArcTo(double x1, double y1, double x2, double y2, double radius);
  void Clear();

protected:
  static NAN_METHOD(New);
  static NAN_METHOD(MoveTo);
  static NAN_METHOD(LineTo);
  static NAN_METHOD(ClosePath);
  static NAN_METHOD(Arc);
  static NAN_METHOD(ArcTo);
  static NAN_METHOD(Clear);

  Path2D();
  virtual ~Path2D();

private:
  canvas::Path2D *path2d;

  friend class CanvasRenderingContext2D;
};

#include "canvas.h"

#endif
