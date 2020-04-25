# ecl-misc
Testing ECL (Embeddable Common Lisp) 
# Procedure Build static libraries (steps):

#### Generate hello.o

```lisp
ecl > (compile-file "hello.lisp" :system-p t)
```

#### Generate bye.o

```lisp
ecl > (compile-file "bye.lisp" :system-p t)
```

#### Generate static library "libhello-bye.a"

```lisp
(c:build-static-library "hello-bye" :lisp-files '("hello.o" "bye.o") 
                                    :init-name "init_hello_bye")
```

## C source

init_hello_bye is referenced in C source.

#### For execute only the lisp function use:

```c
cl_object result = cl_eval(c_string_to_object("(hello)"));
```

#### For print from C/ECL use:

```c
ecl_print(result, ECL_T);
```

#### For newline use:

```c
ecl_terpri(ECL_T);
```

#### Notes of the source
This source begin in:

```c
cl_boot(argc, argv);
```

and end in:

```c
cl_shutdown();
```

### Building ECL (from source)

```bash
wget -c https://common-lisp.net/project/ecl/static/files/release/ecl-20.4.24.tgz in /usr/local/src
tar -xf ecl-20.4.24.tgz
cd ecl-20.4.24/
./configure --prefix=/usr/local
make
make install
```

#### For build my binary with the static library:

```bash
cc -o hello hello-bye.c libhello-bye.a -lecl
./hello
Hello, world
"Bye."
```

#### (about) hello.lisp

In this function return a "hello, world" but using princ

#### (about) bye.lisp

In this function return a "Bye." but using print.
