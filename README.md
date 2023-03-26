# Calculadora_RPC
Calculadora donde las operaciones las realiza un servidor y el cliente llama a
esas operaciones a través de procedimientos remotos (RPC).

La calculadora es capaz de evaluar expresiones matemáticas como:
* 1+2*6/3 ó 1 +2 *6 /3 (no importan los espacios)
* (1+2)*6/3


## Compilación/instalación
```
make -f Makefile.calculadora
```

Esto generará los programas cliente y servidor. En el servidor tiene que estar
ejecutándose el servicio **rpcbind**

```
sudo apt install rpcbind
sudo systemctl start rpcbind
```

Si quieres que el servicio arranque cuando su ordenador lo haga ejecute
```
sudo systemctl enable rpcbind
```


Ejecute el programa servidor y el cliente. Para ejecutar el cliente:
```
./calculadora_cliente host_servidor
```

Estará esperando a que el usuario le introduzca una expresión matemática

## Bugs
La calculadora no reconoce números negativos, produciéndose una interrupción
del programa. Por tanto no puedes realizar operaciones como -5 + 1 pero sí 1-5.

Errores sintácticos como un paréntesis sin cerrar o dos operadores juntos pueden
causar un error fatal.
