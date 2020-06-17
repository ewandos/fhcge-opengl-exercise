#include <GL/glut.h>
#include <cstdio>
#include "tga.h"


#ifndef PP_TEXTURE_LOADER
#define PP_TEXTURE_LOADER

enum TextureId {
  ELF
};

class ppTextureLoader {
  GLuint texture;
public:
  void init();
  GLuint* getTexture();
};

#endif
