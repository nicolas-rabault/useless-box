# My very overkill and very useless box project

It's a box with a switch on it. When you switch it on, the box opens and switches it off. It's very useless.
I created this useless box as a friend's Christmas gift.

This box is also able to detect an approaching user's finger and react to it.
There is an extra independent hatch allowing you to show something (like a hand with the middle finger up for example).

Watch the video :arrow_down:

<a href="http://www.youtube.com/watch?feature=player_embedded&v=QmZF5PnjvrQ" target="_blank">
<img src="http://img.youtube.com/vi/QmZF5PnjvrQ/mqdefault.jpg" alt="Watch the video" />
</a>

The code allows the creation of various funny and adaptive animations.

This project contains everything allowing you to create your overkill useless box at home.
This project uses:

- [Kicad](https://www.kicad.org/) for the hardware design
- [Platformio](https://platformio.org/) as IDE
- [Luos](https://www.luos.io/) as embedded software architecture
- [onshape](https://cad.onshape.com/documents/4a19889a4a07d74346be9010/w/5fd8e8ddfb7a821311b6dcc0/e/9d6ba70ea9a5a293d2a81b44) for the mechanical design

## How to open the electronic design :electric_plug:

Electronics have been based on [Luos example electronic design](https://github.com/Luos-io/Examples/tree/master/Hardware). You can open and modify all of them using Kicad. This design uses the Luos_components library for more information to install and use it read [Luos doc](https://docs.luos.io).
This box is composed of 3 independent boards:

- a [servo shield](https://github.com/Luos-io/luos_engine/tree/main/examples/hardware/l0-shields/l0_servo) mounted on an [l0 board](https://github.com/Luos-io/luos_engine/tree/main/examples/hardware/l0)
- a [distance shield](https://github.com/Luos-io/luos_engine/tree/main/examples/hardware/l0-shields/l0_distance) mounted on an [l0 board](https://github.com/Luos-io/luos_engine/tree/main/examples/hardware/l0)
- a [DC Power Jack board](https://github.com/Luos-io/luos_engine/tree/main/examples/hardware/wiring_and_power/Jack_power_input)

## Software architecture :computer:

The software architecture is based on Luos. It's a modular architecture allowing the creation of independent features and sharing them with the community.
Here is the Luos view of the software architecture :

```
  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃  ╭────────────────── Node 1 ──────────────────   ┃
  ┃  │  Type                Alias               ID   ┃
  ┃  ├> Gate                gate                1    ┃
  ┃  ╰> Pipe                Pipe                2    ┃
╔■┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
║     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
╚════■┫  ╭────────────────── Node 2 ──────────────────   ┃
      ┃  │  Type                Alias               ID   ┃
      ┃  ├> Angle               hatch               3    ┃
      ┃  ├> Angle               finger              4    ┃
      ┃  ├> Angle               bonus_hatch         5    ┃
      ┃  ├> State               button              6    ┃
      ┃  ╰> Unknown             useless_service     7    ┃
    ╔■┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
    ║     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
    ╚════■┫  ╭────────────────── Node 3 ──────────────────   ┃
          ┃  │  Type                Alias               ID   ┃
          ┃  ├> State               led                 8    ┃
          ┃  ╰> Distance            distance            9    ┃
          ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
```

- **Node 1** is just an extra board with a piece of code allowing to display this architecture, test it, and control it.
- **Node 2** is the servo board controlling the 3 servomotors and the button.
- **Node 3** is the distance sensor board. We also use the L0 LED on this one.

The **useless_service** service is the main application managing input and output as well as the animations. This piece of code is completely portable and you can use it in your project with any board or even on a computer if you want to.

## Any questions? :question:

If you have any questions about this project, feel free to contact me on [discord](https://discordapp.com/users/670746400669302786)
