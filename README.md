# arduino-door-lock

Arduino code for digital door lock in my house.

## Features

Unlocking via password input on matrix keyboard on the outside of the apartment.

Unlocking via push button on the inside of the apartment.

## Mechanism

I am using a eletric door lock which can be opened both by using a physical key or turning a small electrical current on.

![image](https://user-images.githubusercontent.com/17460536/212469785-4c65faf5-4706-4fba-b7c1-7952fa0b1ef9.png)

## How is the mechanism activated?

The Arduino code might have multiple different user inputs, such as passwords, push button, fingerprint or RFID for example. But all of those trigger the same electrical current output to a pin on the electric door lock, which opens it.
