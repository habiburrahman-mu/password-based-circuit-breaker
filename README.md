# password-based-circuit-breaker
Password based circuit breaker is a technology where we can control any circuit by a password. If we enter a password the circuit gives a break that means it is on. It can mainly be used in case of electric lines. Nowadays, electrical accidents to the line man are increasing, while repairing the electrical lines due to the lack of communication between the electrical substation and maintenance staff. This project gives a solution to this problem to ensure line man safety. In this proposed system, the control (ON/OFF) of the electrical lines lies with line man. This project is arranged in such a way that to ON/OFF the electrical line. The project is mainly based on Arduino. An Arduino controls all the functions. A matrix keypad is interfaced for taking password. There is a LCD display to read the password. When password is entered by the matrix keypad it is compared with the stored password in the ROM of the Arduino. If the password matches, relay is on. When the relay is on, led is on. If the password doesn’t match the circuit won’t be on.