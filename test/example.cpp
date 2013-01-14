#include <iris/static_scope.hpp>

extern const char some_name[] = "mscope";

class myclass : public iris::static_scope<iris::Info, some_name>
{
public:
  void test()
  {
    slog<iris::Info>("hej");
  }

};

int main(int argc, char ** argv)
{
  myclass a;
  a.test();
}
