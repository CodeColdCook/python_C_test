void test_PyArg_ParseTuple() {
  int ok;

  int i, j;

  long k, l;

  char *s;

  int size;

  ok = PyArg_ParseTuple(args, ""); /* No arguments */

  /* Python call: f() */

  ok = PyArg_ParseTuple(args, "s", &s); /* A string */

  /* Possible Python call: f('whoops!')*/

  ok = PyArg_ParseTuple(args, "lls", &k, &l, &s); /* Two longs and a string */

  /* Possible Python call: f(1, 2,'three') */

  ok = PyArg_ParseTuple(args, "(ii)s#", &i, &j, &s, &size);

  /* A pair of ints and a string, whosesize is also returned */

  /* Possible Python call: f((1, 2),'three') */

  {
    char *file;

    char *mode = "r";

    int bufsize = 0;

    ok = PyArg_ParseTuple(args, "s|si", &file, &mode, &bufsize);

    /* A string, and optionally anotherstring and an integer */

    /* Possible Python calls:

       f('spam')

       f('spam', 'w')

       f('spam', 'wb', 100000) */
  }

  {
    int left, top, right, bottom, h, v;

    ok = PyArg_ParseTuple(args, "((ii)(ii))(ii)",

                          &left, &top, &right, &bottom, &h, &v);

    /* A rectangle and a point */

    /* Possible Python call:

       f(((0, 0), (400, 300)), (10, 10)) */
  }

  {
    Py_complex c;

    ok = PyArg_ParseTuple(args, "D:myfunction", &c);

    /* a complex, also providing a functionname for errors */

    /* Possible Python call:myfunction(1+2j) */
  }
}