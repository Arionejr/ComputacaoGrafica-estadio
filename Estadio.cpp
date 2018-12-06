// **** CABEÇALHO ****
// PROJETO CASA 'L'
// PONTÍFICIA UNIVERSIDADE CATÓLICA DE GOIÁS - PUC-GO
// CURSO: COMPUTACAO GRAFICA - CMP1170
// PROFº: Me. FABIO ASSUNÇÃO
// ALUNO: ARIONE CHAVES GUIMARAES JUNIOR				MATRICULA: 20131002800123
// ALUNO: IAGO CORREIA DE SOUSA							MATRICULA: 20151003303225


  


#include <GL/glu.h>
#include <GL/glut.h>
#include "tgaload.h"


//GLfloat angle, fAspect;
GLfloat ASPECTO, ANGULO;
int x_ini,y_ini, bot;
GLfloat obsX, obsY, obsZ, rotX, rotY;
GLfloat obsX_ini, obsY_ini, obsZ_ini, rotX_ini, rotY_ini;
GLfloat escalaX, escalaY, escalaZ;
#define SENS_ROT 10.0
#define SENS_OBS 10.0
#define SENS_TRANS 10.0   


GLUquadricObj *quadratic;
	

// Qtd máxima de texturas a serem usadas no programa
#define MAX_NO_TEXTURES 100
// vetor com os números das texturas
GLuint texture_id[MAX_NO_TEXTURES];


void initTexture (void)
{
	// Habilita o uso de textura 
	glEnable ( GL_TEXTURE_2D );
	// Define a forma de armazenamento dos pixels na textura (1= alihamento por byte)
	glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );
	// Define quantas texturas serão usadas no programa 
	glGenTextures (MAX_NO_TEXTURES, texture_id);  // Quantidade de texturas, vetor de texturas
	// TEXTURA 0
	texture_id[0] = 1001;
	glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
	image_t temp_image0;
	tgaLoad  ( "imagens/campo4.tga", &temp_image0, TGA_FREE | TGA_LOW_QUALITY );
	
	glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
	image_t temp_image1;
	tgaLoad  ( "imagens/cimento.tga", &temp_image1, TGA_FREE | TGA_LOW_QUALITY );
	
	glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
	image_t temp_image2;
	tgaLoad  ( "imagens/arquibancada.tga", &temp_image2, TGA_FREE | TGA_LOW_QUALITY );
	
	glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
	image_t temp_image3;
	tgaLoad  ( "imagens/grama.tga", &temp_image3, TGA_FREE | TGA_LOW_QUALITY );
	
	glBindTexture ( GL_TEXTURE_2D, texture_id[4] );
	image_t temp_image4;
	tgaLoad  ( "imagens/flamengo.tga", &temp_image4, TGA_FREE | TGA_LOW_QUALITY );	
	
	glBindTexture ( GL_TEXTURE_2D, texture_id[5] );
	image_t temp_image5;
	tgaLoad  ( "imagens/bola.tga", &temp_image5, TGA_FREE | TGA_LOW_QUALITY );
	
}

	
// Função callback chamada para fazer o desenho
void Desenha(void)
{
	// Limpa a janela e o depth buffer
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glClear(GL_COLOR_BUFFER_BIT);   
     
     //ANEIS DA COBERTURA - CILINDROS
	 //ANEL INFERIOR
	 // seleciona e aplica textura 
     gluQuadricTexture(quadratic,texture_id[1]); //CIMENTO
	 glPushMatrix();
     	//gltranslatef
     	glColor3f(2.55f,2.55f,2.55f);
		glRotatef(90,20,0,0);  
		gluCylinder(quadratic,40,31,0,50,50); 
     glPopMatrix();
     
     //ANEL SUPERIOR
	 // seleciona e aplica textura 
     gluQuadricTexture(quadratic,texture_id[1]);	//CIMENTO
	 glPushMatrix();
     	//gltranslatef
     	glTranslatef(0,20,0);
     	glColor3f(2.55f,2.55f,2.55f);
		glRotatef(90,20,0,0);  
		gluCylinder(quadratic,40,31,0,50,50);
		glTranslatef(0,-20,0); // zerando posição		
     glPopMatrix();
     
// componetes do campo de futebol
// -> TRAVES DOS GOLS
     //Trave X+
     glPushMatrix();
     	 glTranslatef(14.5,2,1.5);
	 	 glRotatef(90,1,0,0);
	 	 gluCylinder(quadratic,0.1,0.1,2,50,50);
	 	 glTranslatef(-14.5,-2,-1.5);
      glPopMatrix();
  	  glPushMatrix();
     	 glTranslatef(14.5,2,-1.5);
	 	 glRotatef(90,1,0,0);
	 	 gluCylinder(quadratic,0.1,0.1,2,50,50);
	 	 glTranslatef(-14.5,-2,1.5);
      glPopMatrix();
     glPushMatrix(); // travessão
     	 glTranslatef(14.5,2,-1.5);
	 	 //glRotatef(90,1,0,0);
	 	 gluCylinder(quadratic,0.1,0.1,3,50,50);
	 	 glTranslatef(-14.5,-2,1.5);
      glPopMatrix();
      
      // Trave X-
     glPushMatrix();
     	 glTranslatef(-14.5,2,1.5);
	 	 glRotatef(90,1,0,0);
	 	 gluCylinder(quadratic,0.1,0.1,2,50,50);
	 	 glTranslatef(14.5,-2,-1.5);
      glPopMatrix();
  	  glPushMatrix();
     	 glTranslatef(-14.5,2,-1.5);
	 	 glRotatef(90,1,0,0);
	 	 gluCylinder(quadratic,0.1,0.1,2,50,50);
	 	 glTranslatef(-14.5,-2,1.5);
      glPopMatrix();
     glPushMatrix(); // travessão
     	 glTranslatef(-14.5,2,-1.5);
	 	 //glRotatef(90,1,0,0);
	 	 gluCylinder(quadratic,0.1,0.1,3,50,50);
	 	 glTranslatef(14.5,-2,1.5);
      glPopMatrix();  
	  
// -> PLACAS PUBLICITÁRIAS LATERAIS
		float tamini = -15.0;
		float tamadc =  10.0;

		for(int i=0; i< 3; i++){
	 	 // seleciona e aplica textura 
	 	 glBindTexture ( GL_TEXTURE_2D, texture_id[4] ); //CIMENTO
	     glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(2.55f,2.55f,2.55f);
				//glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(tamini, 0.0f, -10.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(tamini, 1.0f, -10.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f( tamini+tamadc, 1.0f, -10.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f( tamini+tamadc, 0.0f, -10.0f);	 
			glEnd();
	     glPopMatrix();
	     tamini += tamadc;
		}
		glBindTexture ( GL_TEXTURE_2D, 0 ); //CIMENTO
		tamini = -15.0;
		for(int i=0; i< 3; i++){
	 	 // seleciona e aplica textura 
	 	 glBindTexture ( GL_TEXTURE_2D, texture_id[4] ); //CIMENTO
	     glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(2.55f,2.55f,2.55f);
				//glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(tamini, 0.0f, 10.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(tamini, 1.0f, 10.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f( tamini+tamadc, 1.0f, 10.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f( tamini+tamadc, 0.0f, 10.0f);	 
			glEnd();
	     glPopMatrix();
	     tamini += tamadc;
		}
		
// -> PLACAS PUBLICITÁRIAS DE FUNDO
		
		tamini = -10.0;
		tamadc = 5.0;
		for(int i=0; i< 4; i++){
	 	 // seleciona e aplica textura 
	 	 glBindTexture ( GL_TEXTURE_2D, texture_id[4] ); //CIMENTO
	     glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(2.55f,2.55f,2.55f);
				//glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(15.0f, 0.0f, tamini);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(15.0f, 1.0f, tamini);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(15.0f, 1.0f, tamini+tamadc);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(15.0f, 0.0f, tamini+tamadc);	 
			glEnd();
	     glPopMatrix();
	     tamini += tamadc;
		}
		
		tamini = -10.0;
		for(int i=0; i< 4; i++){
	 	 // seleciona e aplica textura 
	 	 glBindTexture ( GL_TEXTURE_2D, texture_id[4] ); //CIMENTO
	     glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(02.55f,2.55f,2.55f);
				//glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0f, 0.0f, tamini);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(-15.0f, 1.0f, tamini);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(-15.0f, 1.0f, tamini+tamadc);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0f, 0.0f, tamini+tamadc);	 
			glEnd();
	     glPopMatrix();
	     tamini += tamadc;
		}
     
     
     
     // CAMPO 
	 // seleciona e aplica textura 
	 glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
     glPushMatrix();
		glBegin(GL_QUADS);
			glColor3f(2.55f, 2.55f, 2.55f);
			//glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0f, 0.1f, -10.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 15.0f, 0.1f, -10.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 15.0f, 0.1f,  10.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0f, 0.1f,  10.0f);	 
		glEnd();
     glPopMatrix();
     glBindTexture ( GL_TEXTURE_2D, 0 );
     
	 glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
     glPushMatrix();
     	 glBegin(GL_POLYGON);
			glColor3f(2.55f, 2.55f, 2.55f);
			//glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.2F,	0.8F); glVertex3f( 17.0f,	0.0f,	 10.0f);
			glTexCoord2f(0.4f, 	0.9f); glVertex3f( 17.0f, 	0.0f,  	-10.0f);
			glTexCoord2f(0.9f, 	0.4f); glVertex3f( 15.0f, 	0.0f,  	-12.0f);	
			glTexCoord2f(0.8f, 	0.2f); glVertex3f(-15.0f, 	0.0f, 	-12.0f);
			glTexCoord2f(0.8f, 	0.2f); glVertex3f(-17.0f, 	0.0f, 	-10.0f);
			glTexCoord2f(0.9f, 	0.4f); glVertex3f(-17.0f, 	0.0f, 	 10.0f);
			glTexCoord2f(0.4f, 	0.4f); glVertex3f(-15.0f, 	0.0f,  	 12.0f);	  
			glTexCoord2f(0.4f, 	0.8f); glVertex3f( 15.0f,	0.0f,	 12.0f);
		 glEnd();
      glPopMatrix();
      glBindTexture ( GL_TEXTURE_2D, 0 ); //default
      
      
      	// bola
      	gluQuadricTexture(quadratic,GL_TRUE);
      	glBindTexture ( GL_TEXTURE_2D, texture_id[5] ); //bola.tga
		glPushMatrix();			
			glTranslatef(0,0.3,0);
			glColor3f(2.55f, 2.55f, 2.55f);
			//glutSolidSphere(1,16,16);
			gluSphere(quadratic,0.2,30,30);
		glPopMatrix();
        // FIM CAMPO
     
     //ARQUIBANCADA EM X
    float vlEsp,A,B,C,D,E,F,G,H,I,J,L,M,N,O,P,Q,R,S,T,U,V,X,Z,K;
    
    vlEsp = 0.4;
	
	A = -15.0;
    B = 0.1  ;
    C = -12.0;
    D = 15.0 ;
    E = 0.5	 ;
    F = C-0.4;
	//--    
    G = -15.0;						//A X
    H =	0.1	 ;						//B Y
	I =	12.0 ;						//C Z
	J =	15.0 ;						//D	X
	L =	0.5	 ;						//E Y
	M =	I+0.4;						//F Z
	//--
	N = -17.0; 						//A X
	O = 0.1	 ;						//B Y
	P = -10.0;						//C Z
 	Q = N-0.4;						//D	X
	R = 0.5	 ;						//E Y
	S = 10.0 ;						//F Z
	//--
	T = 17.0 ;
	U = 0.1	 ;
	V = -10.0;
	X = T+0.4;
	Z = 0.5	 ;
	K = 10.0 ;
    
    
 	 // seleciona e aplica textura 
	 glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
	for (int i = 0; i < 25; i++)
		{	
			//vertical
			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(A, B, C);
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(D, B, C);
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(D, E, C);
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(A, E, C);
	            glEnd();  
	    	glPopMatrix(); 
	    	
     		//horizontal
  			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(A, E, F);
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(D, E, F);
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(D, E, C);
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(A, E, C);
	            glEnd(); 
	    	glPopMatrix();
	    	
					B = B + 0.4;
					C = C - 0.4;
					E = E + 0.4;
					F = F - 0.4;

			
			//vertical
			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(G, H, I);
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(J, H, I);
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(J, L, I);
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(G, L, I);
	            glEnd();  
	    	glPopMatrix(); 
	    	
     		//horizontal
  			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(G, L, M);
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(J, L, M);
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(J, L, I);
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(G, L, I);
	            glEnd(); 
	    	glPopMatrix();
	    	
			    	H += 0.4	;
			    	I += 0.4	;
					L += 0.4	;
					M += 0.4	;
	    	

			
			//------------------------------- ARQUIBANCADAS DE FUNDO DE QUADRA
			
			//vertical
			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(N, O, P);
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(N, O, S);
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(N, R, S);
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(N, R, P);
	            glEnd();  
	    	glPopMatrix(); 
	    	
     		//horizontal
  			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(N, R, P);
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(N, R, S);
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(Q, R, S);
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(Q, R, P);
	            glEnd(); 
	    	glPopMatrix();
	    	
					N -= 0.4	;
					O += 0.4	;
					Q -= 0.4	;
					R += 0.4	;
			

			
			//vertical
			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(T, U, V);
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(T, U, K);
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(T, Z, K);
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(T, Z, V);
	            glEnd();  
	    	glPopMatrix(); 
	    	
     		//horizontal
  			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(T, Z, V);
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(T, Z, K);
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(X, Z, K);
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(X, Z, V);
	            glEnd(); 
	    	glPopMatrix();
	    	
					T += 0.4	;
					U += 0.4	;
					X += 0.4	;
					Z += 0.4	;

			if(i == 9 || i == 14){
				
				for(int pula = 0; pula <3; pula++){

					
					B = B + 0.4;
					C = C - 0.4;
					E = E + 0.4;
					F = F - 0.4;
					
			    	H += 0.4	;
			    	I += 0.4	;
					L += 0.4	;
					M += 0.4	;
			    	
					N -= 0.4	;
					O += 0.4	;
					Q -= 0.4	;
					R += 0.4	;	
				
					T += 0.4	;
					U += 0.4	;
					X += 0.4	;
					Z += 0.4	;
				}
			} 
	    }
	    

	    float AA, AB, AC, AD, AE, AF, AG, AH, AI, AJ, AL, AM, AN, AO, AP, AQ, AR, AS, AT, AU, AV, AX, AZ, AK;
	    
		AA = 15.0	;						//X
		AB = 1.7	;						//Y
		AC = -13.6	;						//Z
		AD = 18.6	;						//X
		AE = AB+0.4 ;						//Y
		AF = -10.0	;						//Z
		//--
		AG = -15.0	;
		AH = AB		;
		AI = AC		;
		AJ = -18.6	;
		AL = AH+vlEsp;
		AM = AF		;
		//--
		AN = 15.0	;
		AO = 1.7	;
		AP = 13.6	;
		AQ = 18.6	;
		AR = AO+vlEsp;
		AS = 10.0	;
		//--
		AT = AG	;
		AU = AB	;
		AV = AP	;
		AX = AJ	;
		AZ = AE	;
		AK = AS	;
		
	    
 	    // seleciona e aplica textura 
	    glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
		for (int j= 5; j < 26; j++)
		{
			
			// CANTO XZ = +-
			// VERTICAL
			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(AA, AB, AC); 			// -> SENTIDO Z NEGATIVO
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(AA, AE, AC); 			// -> SENTIDO Z NEGATIVO
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(AD, AE, AF); 			// -> SENTIDO X POSITIVO
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(AD, AB, AF); 			// -> SENTIDO X POSITIVO
	            glEnd();  
	    	glPopMatrix(); 
	    	
     		//horizontal
  			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(AA, 	 	AE, AC);			// -> SENTIDO Z NEGATIVO
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(AA, 	 	AE, AC-vlEsp);		// -> SENTIDO Z NEGATIVO
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(AD+vlEsp, 	AE, AF);			// -> SENTIDO X POSITIVO
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(AD, 	 	AE, AF);			// -> SENTIDO X POSITIVO
	            glEnd(); 
	    	glPopMatrix();
		

			AB += vlEsp	;
			AD += vlEsp	;
			AE += vlEsp	;
			AC -= vlEsp	;
			
			// CANTO XZ = --
			// VERTICAL
			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(AG, AH, AI); 			// -> SENTIDO Z NEGATIVO
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(AG, AL, AI); 			// -> SENTIDO Z NEGATIVO
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(AJ, AL, AM); 			// -> SENTIDO X POSITIVO
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(AJ, AH, AM); 			// -> SENTIDO X POSITIVO
	            glEnd();  
	    	glPopMatrix(); 
	    	
     		//horizontal
  			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(AG, 	 	AL, AI);			// -> SENTIDO Z NEGATIVO
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(AG, 	 	AL, AI-vlEsp);		// -> SENTIDO Z NEGATIVO
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(AJ-vlEsp, 	AL, AM);			// -> SENTIDO X POSITIVO
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(AJ, 	 	AL, AM);			// -> SENTIDO X POSITIVO
	            glEnd(); 
	    	glPopMatrix();
			
			AH += vlEsp;
			AJ -= vlEsp;
			AL += vlEsp;
			AI -= vlEsp;
			
			//CANTO XZ = ++
			//VERTICAL
			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(AN, AO, AP); 			// -> SENTIDO Z NEGATIVO
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(AN, AR, AP); 			// -> SENTIDO Z NEGATIVO
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(AQ, AR, AS); 			// -> SENTIDO X POSITIVO
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(AQ, AO, AS); 			// -> SENTIDO X POSITIVO
	            glEnd();  
	    	glPopMatrix(); 
	    	
     		//horizontal
  			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(AN, 	 	AR, AP);			// -> SENTIDO Z NEGATIVO
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(AN, 	 	AR, AP+vlEsp);		// -> SENTIDO Z NEGATIVO
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(AQ+ vlEsp, AR, AS);			// -> SENTIDO X POSITIVO
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(AQ, 	 	AR, AS);			// -> SENTIDO X POSITIVO
	            glEnd(); 
	    	glPopMatrix();
			
			AO += vlEsp	;
			AQ += vlEsp	;
			AR += vlEsp ;
			AP += vlEsp	;
			
			// CANTO XZ = -+
			//VERTICAL
			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(AT, AU, AV); 			// -> SENTIDO Z NEGATIVO
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(AT, AZ, AV); 			// -> SENTIDO Z NEGATIVO
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(AX, AZ, AK); 			// -> SENTIDO X POSITIVO
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(AX, AU, AK); 			// -> SENTIDO X POSITIVO
	            glEnd();  
	    	glPopMatrix(); 
	    	
     		//horizontal
  			glPushMatrix();
	            glColor3f(2.55f, 2.55f, 2.55f);
	            glBegin(GL_QUADS);
			    	glTexCoord2f(0.0f, 0.0f); glVertex3f(AT, 	 	AZ, AV);			// -> SENTIDO Z NEGATIVO
			    	glTexCoord2f(1.0f, 0.0f); glVertex3f(AT, 	 	AZ, AV+vlEsp);		// -> SENTIDO Z NEGATIVO
		 			glTexCoord2f(1.0f, 1.0f); glVertex3f(AX-vlEsp,  AZ, AK);			// -> SENTIDO X POSITIVO
			    	glTexCoord2f(0.0f, 1.0f); glVertex3f(AX, 	 	AZ, AK);			// -> SENTIDO X POSITIVO
	            glEnd(); 
	    	glPopMatrix();
			
			AU += vlEsp	;
			AX -= vlEsp	;
			AZ += vlEsp ;
			AV += vlEsp	;
			
			if(j == 10 || j == 15){
				
				for(int pula = 0; pula <3; pula++){

					
					AB += vlEsp	;
					AD += vlEsp	;
					AE += vlEsp	;
					AC -= vlEsp	;
					
					AH += vlEsp;
					AJ -= vlEsp;
					AL += vlEsp;
					AI -= vlEsp;
					
					AO += vlEsp	;
					AQ += vlEsp	;
					AR += vlEsp ;
					AP += vlEsp	;
					
					AU += vlEsp	;
					AX -= vlEsp	;
					AZ += vlEsp ;
					AV += vlEsp	;			
			
				}
			}			
	    
		}glBindTexture ( GL_TEXTURE_2D, 0);
		
		
		// estruturas cilindricas 3 niveis
		
		// seleciona e aplica textura 
	 	glBindTexture ( GL_TEXTURE_2D, texture_id[1] ); //CIMENTO		
		
		glPushMatrix();		
		GLUquadricObj *obj[216];
		for (int i = 0; i < 216; i++)
		{
		   	obj[i] = gluNewQuadric();
		}

		float raio = 32.0;
		float adRaio = 3.0;
		glRotatef(270,1,0,0);
		glTranslatef(raio, 0.0f, 0.0f);
		int index = 0;
		
		for(int i=0; i<72; i++){
			
				gluQuadricTexture(obj[index],texture_id[1]);
				//interno
				gluCylinder(obj[index], 0.5, 0.5, 20, 50, 50);
				glTranslatef(raio*(-1), 0.0f, 0.0f);
				glRotatef(5,0,0,1);
				glTranslatef(raio, 0.0f, 0.0f);
				index += 1;
		}
		
		
		glTranslatef(raio*(-1), 0.0f, 0.0f);
		raio += adRaio;
		glTranslatef(raio, 0.0f, 0.0f);
		
		for(int i=0; i<72; i++){
				
				gluQuadricTexture(obj[index],texture_id[1]);
				//interno
				gluCylinder(obj[index], 0.5, 0.5, 20, 50, 50);
				glTranslatef(raio*(-1), 0.0f, 0.0f);
				glRotatef(5,0,0,1);
				glTranslatef(raio, 0.0f, 0.0f);
				index += 1;
		}
		
		glTranslatef(raio*(-1), 0.0f, 0.0f);
		raio += adRaio;
		glTranslatef(raio, 0.0f, 0.0f);
		
		for(int i=0; i<72; i++){

				gluQuadricTexture(obj[index],texture_id[1]);
				//interno
				gluCylinder(obj[index], 0.5, 0.5, 20, 50, 50);
				glTranslatef(raio*(-1), 0.0f, 0.0f);
				glRotatef(5,0,0,1);
				glTranslatef(raio, 0.0f, 0.0f);
				index += 1;
		}
						
	glEnd();
	glPopMatrix();


		   
		        
	    glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 20.0, 20.0, 1.0};
	
	quadratic = gluNewQuadric(); // cilindro 

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	 
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

    //angle=45;
    ANGULO = 45;
    rotX = rotY = 0;
    obsX = obsY = 0;
    obsZ = 60;//Voltar para 10 -- define posição da geração da tela, o ponto C
    escalaX = escalaY = escalaZ = 1;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void) //equivalente ao posiciona observador
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    //gluPerspective(angle,fAspect,0.4,500);
    gluPerspective(ANGULO, ASPECTO, 0.4, 500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
    //gluLookAt(0,80,200, 0,0,0, 0,1,0);
    //gluLookAt(obsX, obsY, obsZ, 0,0,0, 0,1,0);
    glTranslatef(-obsX, -obsY, -obsZ);/*Translata a cÃ¢mera para essas variÃ¡veis*/
    glRotatef(rotX,1,0,0);/*Rotacionar a cÃ¢mera para essas coordenadas*/
    glRotatef(rotY,0,1,0); 
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	//fAspect = (GLfloat)w/(GLfloat)h;
	ASPECTO = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	/*if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}*/
	if(state == GLUT_DOWN){
		x_ini = x;
        y_ini = y;
        obsX_ini = obsX;
        obsY_ini = obsY;
        obsZ_ini = obsZ;
        rotX_ini = rotX;
        rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

        void motion(int x, int y){
            if(bot == GLUT_LEFT_BUTTON){//RotaÃ§Ã£o
                int deltaX = x_ini - x;
                int deltaY = y_ini - y; 
                rotX = rotX_ini - deltaY/ SENS_ROT;
                rotY = rotY_ini - deltaX/ SENS_ROT;
             }
             else if (bot == GLUT_RIGHT_BUTTON){//Zoom
                 int deltaZ = y_ini - y;
                 obsZ = obsZ_ini + deltaZ/ SENS_OBS;
             }
             else if (bot == GLUT_MIDDLE_BUTTON){//Correr
                 int deltaX = x_ini - x;
                 int deltaY = y_ini - y;
                 obsX = obsX_ini + deltaX/ SENS_TRANS;
                 obsY = obsY_ini + deltaY/ SENS_TRANS;
             }
             EspecificaParametrosVisualizacao();
             glutPostRedisplay();
        }

// Programa Principal
int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutCreateWindow("Estadio Mané Garrincha");
	glutDisplayFunc(Desenha);
	initTexture();
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutMotionFunc(motion);
	Inicializa();
	glutMainLoop();
}