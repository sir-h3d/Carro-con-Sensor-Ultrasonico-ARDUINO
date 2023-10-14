# Control de Carro con Sensor Ultrasónico

Este proyecto implementa un control de un carro utilizando un sensor ultrasónico para detectar obstáculos y tomar decisiones de movimiento en consecuencia. El carro se moverá hacia adelante hasta que detecte un obstáculo cercano y luego tomará acciones para evitar la colisión.

## Componentes

- Arduino (o compatible)
- Sensor ultrasónico HC-SR04
- Motores DC para el control del movimiento del carro

## Biblioteca NewPing

La biblioteca `NewPing` se utiliza para manejar el sensor ultrasónico. Proporciona una interfaz sencilla para medir la distancia y puede ser configurada con los pines de disparo y eco, así como la distancia máxima para la detección.

## Configuración del Hardware

El código asume la siguiente configuración de hardware:

- Pin TRIG del sensor ultrasónico conectado a A0 en Arduino.
- Pin ECHO del sensor ultrasónico conectado a A1 en Arduino.
- El rango máximo de detección del sensor está configurado en 200 cm.

Asegúrate de conectar los componentes según estas especificaciones antes de cargar el código en tu Arduino.

## Funcionamiento

El carro se mueve hacia adelante hasta que el sensor ultrasónico detecta un obstáculo a menos de 15 cm de distancia. En ese punto, el carro se detendrá y tomará medidas evasivas:

- Retrocederá durante 1 segundo.
- Luego, girará hacia la dirección con más espacio libre (derecha o izquierda) y continuará moviéndose hacia adelante.

El estado del carro se muestra en el monitor serial, incluyendo la distancia detectada por el sensor ultrasónico.

## Instrucciones de Uso

1. Conecta el hardware según la configuración especificada.
2. Carga el código en tu Arduino.
3. Abre el monitor serial para ver la información sobre el funcionamiento del carro.
4. Observa cómo el carro evita obstáculos mientras se mueve hacia adelante.

## Notas

- Asegúrate de calibrar el sensor ultrasónico y ajustar la configuración según tus necesidades.
- Este es un proyecto básico y se pueden realizar mejoras adicionales para un comportamiento más sofisticado.

## Créditos

Este proyecto utiliza la biblioteca `NewPing` para el manejo del sensor ultrasónico.

Autor: Henry De la torre

