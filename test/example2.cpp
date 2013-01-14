#include <iris/static_scope.hpp>
#include <iris/severity_type.hpp>

struct Tester : public iris::static_scope<iris::Warning>
{
  void doit()
  {
    slog<iris::Debug>("1");
    slog<iris::Fatal>("1");
  }

};

int main(int arc, char** argv)
{
  iris::glog<iris::Warning>("Global Test");
  iris::glog<iris::Warning>("Global Test 2",
                            "Arg1", iris::arg<int>(5));

  Tester t;
  t.doit();
  return 0;
}
