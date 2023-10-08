#include <Windows.h>
#include <C:\Users\azner\OneDrive\Escritorio\Universidad\Año 3\Herr. de Computación\Codigos\Scaling\GLUT\glut.h>

int cx0 = 25;
int cx1 = -25;
int cy0 = 25;
int cy1 = -25;
void inicio() {
    glMatrixMode(GL_PROJECTION);//sirve para el uso de la pantalla
    gluOrtho2D(-50,50,-50,50);//2 primeros inicio y fin de las x y la segunda inicio de la y y fin
    glClearColor(0.0,0.0,1.0,0.0);//Colores RGB
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT);
	//inserte su codigo aqui
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(cx0, cy0); glVertex2i(cx1, cy0);
    glVertex2i(cx1, cy1); glVertex2i(cx0, cy1);
    glEnd();
}

void Functecla (int key, int x, int y){
    if(key==GLUT_KEY_UP){
        cx0 += 10;
        cx1 -= 10;
        cy0 += 10;
        cy1 -= 10;
    }
    if (key == GLUT_KEY_DOWN)
    {
        cx0 -= 10;
        cx1 += 10;
        cy0 -= 10;
        cy1 += 10;
    }
    glutPostRedisplay();
}

main(int argc, char *argv[]) {
    glutInit(&argc, argv);//inicializa las funciones de GLUT
    glutInitWindowSize(500,500);//ancho y largo de la pantalla
    glutInitWindowPosition(100,100);//Posicioin de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Sesgado");
    inicio();
    glutDisplayFunc(pantalla);
    glutSpecialFunc(Functecla);
    glutMainLoop();//se repite y no se cierra

    return EXIT_SUCCESS;
}