const TAM_MSG = 300;
typedef string msg_error<TAM_MSG>;

const TAM_EXPR_MATEMATICA = 1000;
typedef string expr_mat<TAM_EXPR_MATEMATICA>; 

union calc_res switch (int error) {
   case 0:
      double resultado; /* Si no hay error devolvemos el resultado */
   case 1:
      msg_error msg_error; /* Hay error. El mensaje describe cual*/
};

program CALCULADORA {
   version CALC_VER {
      calc_res CALCULA(expr_mat) = 1;
   } = 1;
} = 0x20000001;