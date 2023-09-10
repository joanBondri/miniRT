# MiniRT - Raytracing Graphics Engine

![GitHub last commit](https://img.shields.io/github/last-commit/joanBondri/MiniRT)

## Overview

MiniRT is a project created as part of the "MiniRT" curriculum at École 42, designed to provide an introduction to the world of computer graphics and raytracing. The goal of this program is to generate computer-generated images that represent scenes from specific angles and positions, defined by simple geometric objects, and lit by customizable lighting systems. MiniRT is developed using the miniLibX library and offers a range of features for rendering scenes.

## Features

- Raytracing protocol-based rendering.
- Simple geometric objects: plane, sphere, and cylinder.
- Fluid window management: window switching, minimization, etc.
- Resolution change without altering the scene's content.
- Support for transformations: translation and rotation of objects, lights, and cameras.
- Lighting features: ambient and diffuse lighting, spot brightness, hard shadows.
- Scene description via a text file with the .rt extension.
- Error handling for misconfigurations in scene description files.
- Support for Ambient, Sphere, Cylinder, Plane, Camera, and Light elements in scene files.

## Getting Started

### Prerequisites

Before you begin, ensure you have the following requirements:

- A Unix-based operating system (Linux).
- [miniLibX](https://github.com/42Paris/minilibx-linux) library installed on your system.

### Installation

1. Clone this repository to your local machine.

```shell
git clone https://github.com/joanBondri/MiniRT.git
cd MiniRT
```

2. Build the project using the provided Makefile.

```shell
make
```

## Usage

To run MiniRT, execute the following command:

```shell
./MiniRT path_to_scene.rt
```

Replace `path_to_scene.rt` with the path to your scene description file.

### Scene Description

The scene is defined in a text file with the .rt extension. You can create scenes by specifying elements in a specific order:

- Ambient lighting (A)
- Camera (C)
- Light (L)
- Sphere (sp)
- Plane (pl)
- Cylinder (cy)

Example scene description:

```plaintext
A 0.2 255,255,255
C -50.0,0,20 0,0,1 70
L -40.0,50.0,0.0 0.6 10,0,255
pl 0.0,0.0,0.0 0.0,1.0,0.0 0,0,225
sp 0.0,0.0,20.6 12.6 255,0,0
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
```

## Testing

The project may include test scenes to showcase its functionality. You can create your own scenes by following the scene description format.

## Images

![image](https://github.com/joanBondri/miniRT/assets/51259134/c7b377b4-a6be-4b9a-af3f-e11da8331f5c)
![image](https://github.com/joanBondri/miniRT/assets/51259134/85bcbd43-5469-48a5-bef2-3d7ef5046a2d)
![image](https://github.com/joanBondri/miniRT/assets/51259134/e570501f-7b44-4a77-8a19-81e50d9396fe)
