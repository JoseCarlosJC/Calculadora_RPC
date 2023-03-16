union calc_res switch (int error) {
   case 0:
      double resultado; /* Si no hay error devolvemos el resultado */
   
   default:
      void; 
};

program CALCULADORA {
   version CALC_VER {
      double SUMA(double, double) = 1;
      double RESTA(double, double) = 2;
      double MULTIPLICA(double, double) = 3;
      double DIVIDE(double, double) = 4;
   } = 1;
} = 0x20000001;