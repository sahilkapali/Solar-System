# 🌌 Solar System Simulation

This is a **3D Solar System Simulation** written in **C++** using **OpenGL** and **GLUT**. It visually represents the Sun and 8 orbiting planets, complete with orbit paths, self-rotation, and orbital movement. Users can interact with the simulation using the mouse and keyboard for zoom and view rotation.

---

## 🚀 Features

- Realistic 3D visualization of the Sun and planets  
- Individual orbits and self-rotations for each planet  
- Zoom in/out using mouse scroll  
- Rotate view by dragging with the left mouse button  
- Speed control using arrow keys  
- Pause/resume animation (toggle-able in the code)

---

## 🖼️ Screenshots

> *(Add screenshots here after running the app — e.g., solar system overview, close-up of planets, zoomed-out view)*

---

## 🛠️ Requirements

To run this simulation, you'll need:

- C++ compiler (G++, Clang, etc.)
- OpenGL and GLUT libraries installed

For Linux (Ubuntu/Debian):
```bash
sudo apt-get install freeglut3-dev
```
Windows:
Install FreeGLUT

Use an IDE like Code::Blocks, Visual Studio, or compile with MinGW

Build Instructions
Compile & Run
Linux/macOS:
```bash
Copy
Edit
g++ solar_system.cpp -o solar_system -lGL -lGLU -lglut
./solar_system
```
Windows (MinGW):
```bash
Copy
Edit
g++ solar_system.cpp -o solar_system -lfreeglut -lopengl32 -lglu32
solar_system.exe
```
🎮 Controls
Action	Control
Zoom in/out	Mouse scroll up/down
Rotate view	Drag with left mouse
Increase speed	↑ Up arrow
Decrease speed	↓ Down arrow
Pause/resume animation	(Modify isPaused in code)

🧠 Concepts Demonstrated
OpenGL lighting, materials, and camera control

3D transformations (glTranslate, glRotate)

Simulation timing using glutTimerFunc

Interactive input handling via GLUT callbacks

📁 File Structure
plaintext
Copy
Edit
solar_system.cpp    // Main source file
README.md           // Project documentation
📚 License
This project is licensed under the MIT License.

vbnet
Copy
Edit
MIT License

Copyright (c) [2025]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
🙌 Acknowledgments
OpenGL

FreeGLUT

Planet color data inspired by general planetary appearances

Feel free to ⭐ star this repository, fork it, or open issues/pull requests for suggestions and improvements!

vbnet
Copy
Edit

Let me know if you want a separate `LICENSE` file or additional badges for GitHub Actions, platforms supported, etc.




 Build Instructions
Compile & Run
Linux/macOS:
bash
Copy
Edit
g++ solar_system.cpp -o solar_system -lGL -lGLU -lglut
./solar_system
Windows (MinGW):
bash
Copy
Edit
g++ solar_system.cpp -o solar_system -lfreeglut -lopengl32 -lglu32
solar_system.exe
🎮 Controls
Action	Control
Zoom in/out	Mouse scroll up/down
Rotate view	Drag with left mouse
Increase speed	↑ Up arrow
Decrease speed	↓ Down arrow
Pause/resume animation	(Modify isPaused in code)

🧠 Concepts Demonstrated
OpenGL lighting, materials, and camera control

3D transformations (glTranslate, glRotate)

Simulation timing using glutTimerFunc

Interactive input handling via GLUT callbacks

📁 File Structure
plaintext
Copy
Edit
solar_system.cpp    // Main source file
README.md           // Project documentation
📚 License
This project is licensed under the MIT License.

vbnet
Copy
Edit
MIT License

Copyright (c) [2025]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
🙌 Acknowledgments
OpenGL

FreeGLUT

Planet color data inspired by general planetary appearances

Feel free to ⭐ star this repository, fork it, or open issues/pull requests for suggestions and improvements!

vbnet
Copy
Edit

Let me know if you want a separate `LICENSE` file or additional badges for GitHub Actions, platforms supported, etc.




