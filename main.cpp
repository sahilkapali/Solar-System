#include <GL/glut.h>  // Includes the OpenGL Utility Toolkit (GLUT) library
#include <cmath>       // Includes the math library for mathematical functions (e.g., M_PI)


// Constants defining the Sun and planet properties
const float SUN_RADIUS = 2.0f;  // The radius of the sun
const float PLANET_RADII[] = {0.2f, 0.3f, 0.5f, 0.4f, 1.0f, 0.9f, 0.7f, 0.6f};  // The radii of the planets
const float PLANET_DISTANCES[] = {4.0f, 6.0f, 8.0f, 10.0f, 14.0f, 18.0f, 22.0f, 26.0f};  // The orbital distances of the planets from the sun
float PLANET_SPEEDS[] = {1.0f, 0.8f, 0.6f, 0.5f, 0.4f, 0.3f, 0.25f, 0.2f};  // The speeds of the planet orbits (variable)
const float PLANET_ROTATION_SPEEDS[] = {3.0f, 2.5f, 1.8f, 1.5f, 1.2f, 1.0f, 0.8f, 0.7f};  // The speeds of planet rotation on their axes

// RGB colors for each planet
const float PLANET_COLORS[][3] = {
    {0.5f, 0.5f, 0.5f}, {1.0f, 0.8f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f},
    {0.8f, 0.5f, 0.2f}, {0.8f, 0.8f, 0.5f}, {0.2f, 0.8f, 1.0f}, {0.0f, 0.0f, 0.5f}
};

// Arrays to store angles for planet orbits and rotations
float planetAngles[8] = {0.0f};  // Orbit angles of the planets
float planetRotations[8] = {0.0f};  // Rotation angles of the planets on their axes
float zoom = 20.0f;  // Zoom level for the camera (initially far)
float rotationX = 0.0f, rotationY = 0.0f;  // Rotation angles for camera (view rotation)
bool isPaused = false;  // Whether the simulation is paused
bool mouseDown = false;  // Whether the mouse is clicked
int lastMouseX, lastMouseY;  // To store the last mouse position
float speedMultiplier = 1.0f;  // The multiplier for planet speed (can be changed by the user)

// Initialize OpenGL settings
void init() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing to handle 3D rendering properly
    glEnable(GL_LIGHTING);  // Enable lighting
    glEnable(GL_LIGHT0);  // Enable a light source
    glEnable(GL_COLOR_MATERIAL);  // Enable color material, allowing object colors to be affected by lighting
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black
}

// Function to draw a sphere with a given radius
void drawSphere(float radius) {
    glutSolidSphere(radius, 50, 50);  // Draws a solid sphere with the given radius, using 50 subdivisions
}

// Function to draw a circular orbit at a given radius
void drawOrbit(float radius) {
    glBegin(GL_LINE_LOOP);  // Begin a loop for drawing lines
    for (int i = 0; i < 360; i++) {  // Loop through 360 degrees to draw a circle
        float angle = i * M_PI / 180.0f;  // Convert degrees to radians
        glVertex3f(radius * cos(angle), 0.0f, radius * sin(angle));  // Draw each vertex of the orbit
    }
    glEnd();  // End the loop
}

// Main display function to render the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear the color and depth buffers
    glLoadIdentity();  // Reset the transformation matrix
    gluLookAt(0.0, zoom, 40.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  // Set the camera view
    glRotatef(rotationX, 1.0, 0.0, 0.0);  // Rotate the view along the X-axis
    glRotatef(rotationY, 0.0, 1.0, 0.0);  // Rotate the view along the Y-axis

    glPushMatrix();  // Save the current matrix
    glColor3f(1.0, 0.5, 0.0);  // Set color to orange for the sun
    drawSphere(SUN_RADIUS);  // Draw the sun
    glPopMatrix();  // Restore the matrix

    // Loop to draw each planet
    for (int i = 0; i < 8; ++i) {
        glColor3f(1.0, 1.0, 1.0);  // Draw the orbit in white
        drawOrbit(PLANET_DISTANCES[i]);  // Draw the orbit at the planet's distance

        glPushMatrix();  // Save the current matrix
        glRotatef(planetAngles[i], 0.0, 1.0, 0.0);  // Rotate by the current angle for the orbit
        glTranslatef(PLANET_DISTANCES[i], 0.0, 0.0);  // Move to the planet's position

        glRotatef(planetRotations[i], 0.0, 1.0, 0.0);  // Rotate the planet on its axis

        glColor3f(PLANET_COLORS[i][0], PLANET_COLORS[i][1], PLANET_COLORS[i][2]);  // Set the color of the planet
        drawSphere(PLANET_RADII[i]);  // Draw the planet with its radius

        glPopMatrix();  // Restore the matrix
    }

    glutSwapBuffers();  // Swap the front and back buffers to display the result
}

// Update function to animate the simulation
void update(int value) {
    if (!isPaused) {  // If not paused, update the planet positions and rotations
        for (int i = 0; i < 8; ++i) {
            planetAngles[i] += PLANET_SPEEDS[i] * speedMultiplier;  // Update orbit angle with speed multiplier
            if (planetAngles[i] > 360) planetAngles[i] -= 360;  // Keep angle within 0-360 degrees
            planetRotations[i] += PLANET_ROTATION_SPEEDS[i] * speedMultiplier;  // Update rotation angle
            if (planetRotations[i] > 360) planetRotations[i] -= 360;  // Keep rotation within 0-360 degrees
        }
    }
    glutPostRedisplay();  // Redraw the scene
    glutTimerFunc(16, update, 0);  // Call the update function every 16ms for smooth animation
}

// Mouse function to handle mouse input
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {  // Left mouse button pressed
        mouseDown = true;
        lastMouseX = x;
        lastMouseY = y;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {  // Left mouse button released
        mouseDown = false;
    }

    // Mouse scroll to zoom in or out
    if (button == 3) zoom -= 1.0f;  // Zoom in (scroll up)
    if (button == 4) zoom += 1.0f;  // Zoom out (scroll down)
    glutPostRedisplay();  // Redraw the scene
}

// Mouse motion function for rotating the view
void mouseMotion(int x, int y) {
    if (mouseDown) {  // If the mouse is clicked, rotate the view
        rotationY += (x - lastMouseX) * 0.2f;  // Rotate around Y-axis based on mouse movement
        rotationX += (y - lastMouseY) * 0.2f;  // Rotate around X-axis based on mouse movement
        lastMouseX = x;
        lastMouseY = y;
        glutPostRedisplay();  // Redraw the scene
    }
}

// Function to handle special key presses (up and down arrows for speed control)
void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {  // If the up arrow key is pressed
        speedMultiplier += 0.1f;  // Increase speed
        if (speedMultiplier > 5.0f) speedMultiplier = 5.0f;  // Cap the speed at 5.0
    }
    if (key == GLUT_KEY_DOWN) {  // If the down arrow key is pressed
        speedMultiplier -= 0.1f;  // Decrease speed
        if (speedMultiplier < 0.1f) speedMultiplier = 0.1f;  // Prevent speed from going below 0.1
    }
}

// Function to handle window resizing
void reshape(int w, int h) {
    glViewport(0, 0, w, h);  // Set the view port to the new window size
    glMatrixMode(GL_PROJECTION);  // Switch to projection matrix
    glLoadIdentity();  // Reset projection matrix
    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);  // Set up perspective projection
    glMatrixMode(GL_MODELVIEW);  // Switch back to model view matrix
}

// Main function to initialize and run the simulation
int main(int argc, char** argv) {
    glutInit(&argc, argv);  // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // Set display mode for double buffering, RGB, and depth testing
    glutInitWindowSize(800, 600);  // Set initial window size
    glutCreateWindow("Solar System Simulation");  // Create the window with a title
    init();  // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set the display function
    glutReshapeFunc(reshape);  // Set the reshape function for resizing
    glutMouseFunc(mouse);  // Set the mouse input function
    glutMotionFunc(mouseMotion);  // Set the mouse motion function
    glutSpecialFunc(specialKeys);  // Set the special keys (arrow keys) function
    glutTimerFunc(16, update, 0);  // Start the update function for animation
    glutMainLoop();  // Start the GLUT main loop
    return 0;  // Return from main (never reached)
}
