# Lectura de un botón usando Interrupciones sin eliminar rebotes

## Introducción 

Una interrupcion es un evento externo que interrumpe la ejecución normal del programa y da prioridad a una función asociada a esa interrupción. 
Esto permite que el microcontrolador pueda atender eventos importante en cualquier instante de tiempo y se ejecute a gran velocidad.


## Algunos Métodos de la clase InterruptIn

- `pin.rise(Función a ejecutar)` : Este método se utiliza para especificar que la función  asociada a la interrupción se llamará automáticamente cuando se 
detecte un flanco ascendente  (de bajo a alto) en el pin especificado.

- `pin.fall(Función a ejecutar)` : Este método se utiliza para especificar que la función asociada a la interrupción se llamará automáticamente cuando se 
detecte un flanco descendente  (de alto a bajo) en el pin especificado.

- `pin.mode(Tipo de entrada)` : Este método se utiliza para establecer la resistencia de entrada de la interrupción. Los parámetros disponibles 
son [`PullUp`](https://github.com/crelec/EjemploBoton1#resistencia-pull-up), [`PullDown`](https://github.com/crelec/EjemploBoton1#resistencia-pull-down) y `PullNone`.

Es importante saber que utilizar estos métodos se pueden ahorrar si declaramos inicialmente los parámetros al crear un objeto de la clase **InterruptIn**.


Para obtener la documentación completa de la clase InterruptIn, clic [aqui](https://os.mbed.com/docs/mbed-os/v6.15/apis/interruptin.html "Interrupciones API")


## Ejemplo del código

Este ejemplo de código es una alternativa al [Ejemplo 2](https://github.com/crelec/EjemploBoton2) en donde se mostró el problema de los rebotes en los botones,
Por lo tanto el [montaje](https://github.com/crelec/EjemploBoton2#montaje) va a ser el mismo.

La gran diferencia entre esta alternativa y el Ejemplo 2 es que, en este ejemplo, el microcontrolador realiza la acción de contar y actualizar los pines de 
salida cuando se detecta un flanco de bajada en el pin `PC_13` osea una sola lectura. Es decir, cuando se detecta que el pin pasa de un voltaje alto a un voltaje bajo. Sin embargo, 
en el Ejemplo 2, para realizar la acción de contar y actualizar los pines de salida, el microcontrolador tiene que estar continuamente leyendo el pin de 
entrada `PC_13` cada cierto tiempo hasta que se cumpla la condición establecida, gastando recursos innecesariamente que podrían ser aprovechados de otra forma.
