# typed: false
class A; end
  sig{A.b}
#     ^ error: Method does not exist on `Sorbet::Private::Builder`
#     ^^^ error: Method `b` does not exist on `Sorbet::Private::Builder`
# ^^^^^^^^ error: Malformed `sig`: No return type specified. Specify one with .returns()
def foo; end