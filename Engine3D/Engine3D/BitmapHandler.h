#pragma once
#include <GL/glew.h>
#include <string>

class BitmapHandler {
public:
    BitmapHandler();
    ~BitmapHandler();

    bool LoadTexture(const std::string& fileName);
    GLuint GetTextureID() const;

private:
    GLuint textureID;
    void FreeTexture();
};
