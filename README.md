## 📝 Descripción
Prototipo de robot con control inalámbrico y arquitectura distribuida. Este proyecto integra el diseño mecánico 3D, el control de potencia y la programación de sistemas embebidos para la gestión de 7 grados de libertad.
![IMG_20230110_195536](https://github.com/user-attachments/assets/a89144b9-617e-41e8-8161-cb84d37b816e)
## 🚀 Características Técnicas
- **Arquitectura:** Control distribuido con Arduino Nano y Pro Mini.
- **Actuadores:** Servomotores de alto torque (SG995) y motorreductores.
- **Control:** Comunicación inalámbrica mediante Bluetooth HC-06 y App móvil.
- **Gestión de Energía:** Regulación mediante módulos Step-Down LM2596 para estabilidad del sistema.

## 🛠️ Tecnologías utilizadas
- **Hardware:** Arduino, Drivers DRV8833.
- **Software:** Arduino IDE (C++).
![IMG_20230111_080845](https://github.com/user-attachments/assets/9ee7d9de-0943-43b7-b041-e289981226ce)

## 📂 Estructura del Repositorio
- `Control_principal-Master.ino` : Contiene codigo del microcontrolador Master.
-  `Slaver.ino` : Contiene codigo del microcontrolador Slave.
- `control_mobil.kwl`: Contiene la configuracion del control mediante el mobil(Bluetooth Electronics).


