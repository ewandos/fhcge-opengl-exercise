#include "ppTextureLoader.h"

void ppTextureLoader::init() {
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  GLsizei w, h;
  tgaInfo *info = 0;
  int mode;

  info = tgaLoad("elf.tga");

  if (info->status != TGA_OK) {
    fprintf(stderr, "error loading texture image: %d\n", info->status);
    return;
  }

  if (info->width != info->height) {
    fprintf(stderr, "Image size %d x %d is not rectangular, giving up.\n", info->width, info->height);
    return;
  }

  mode = info->pixelDepth / 8;  // will be 3 for rgb, 4 for rgba
  glGenTextures(1, &this->texture);


  glBindTexture(GL_TEXTURE_2D, this->texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

  // Upload the texture bitmap.
  w  = info->width;
  h = info->height;

  GLint format = (mode == 4) ? GL_RGBA : GL_RGB;
  glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format,
               GL_UNSIGNED_BYTE, info->imageData);

  tgaDestroy(info);
}

GLuint* ppTextureLoader::getTexture() {
  return &this->texture;
}
