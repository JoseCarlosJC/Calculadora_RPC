union calc_res switch (int error) {
   case 0:
      double resultado; /* Si no hay error devolvemos el resultado */
   default:
      void; /* Hay error: en este caso división por 0 */
};

program CALCULADORA {
   version CALC_VER {
      calc_res SUMA(double, double) = 1;
      calc_res RESTA(double, double) = 2;
      calc_res MULTIPLICA(double, double) = 3;
      calc_res DIVIDE(double, double) = 4;
   } = 1;
} = 0x20000001;