# OOPs

Through this project,we have learn about OOPs which are described by the pillar of OOPs as well as how we have use them.

## Encapsulation

In this project, we have packed the data and function a single entity with the help of `C++` keyword ***`class`***

In every [header files](../../include/Client/), we can seen that we have create a class to bind its data and function associated with that data.

Moreover, we have discard the use of `global function` and rather focused over `local function` which greatly support **encapsulation**.

## Abstraction
Abstraction automatically comes with the use of classes and functions. We have used different meaningful named function to perform specific task without the need of knowing whats happening in background in detail. 

Different rendering, playing sound, resetting variables and rendering texts have been done by using simple meaningful named function which does its task in background. 

In this way, we have used abstraction in our project.

## Inheritance

<p align="center"> 
   <img src= "./images/Inheritance Diagram.png" height="500" width="800">
</p>

- In this project we had use two types of inheritance.
  - Mulitple Inheritance
    In file, [`phone.hpp`](../../include/Client/phone.hpp#L14)
  - Hierarchial Inheritance
    In file, [`audio.hpp`](../../include/Client/audio.hpp#L9) and [`tone`](../../include/Client/tone.hpp#L27)

In the above images, the _dotted line(- - - -)_ represents the _object of that class_ and _solid line_ represents the _inheritance_.

## Polymorphism

In C++, we can achieve polymorphism via two ways:

- Function Overloading
  We have overloading `constructor`(special function) to show compile time polymorphism in following files:

  - [tone.hpp](../../include/Client/tone.hpp#L36#L38)
  - [audio.hpp](../../include/Client/audio.hpp#L18#L19)
  - [window.hpp](../../include/Client/window.hpp#L48#49)
  - [texture.hpp](../../include/Client/texture.hpp#L34#L44)

- Virtual Function

  We have use `pure virtual function` to show run time polymorphism in [sound.hpp](../../include/Client/sound.hpp#L16#L17)
