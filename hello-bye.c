#include <ecl/ecl.h>

int
main(int argc, char **argv)
{
  cl_boot(argc, argv);
  extern void init_hello_bye(cl_object cblock);
  ecl_init_module(NULL, init_hello_bye);

  cl_object result = cl_eval(c_string_to_object("(hello)"));
  //ecl_print(result, ECL_T);

  cl_object result0 = cl_eval(c_string_to_object("(bye)"));
  //ecl_print(result0, ECL_T);

  ecl_terpri(ECL_T);
  
  cl_shutdown();

  return 0;
}
