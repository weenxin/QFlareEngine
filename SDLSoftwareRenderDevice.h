#ifndef SDLSOFTWARERENDERDEVICE_H
#define SDLSOFTWARERENDERDEVICE_H



#include "RenderDevice.h"

/** Provide rendering device using SDL_BlitSurface backend.
 *
 * Provide an SDL_BlitSurface implementation for renderning a Renderable to
 * the screen.  Simply dispatches rendering to SDL_BlitSurface().
 *
 * As this is for the FLARE engine, the implementation uses the engine's
 * global settings context, which is included by the interface.
 *
 * @class SDLSoftwareRenderDevice
 * @see RenderDevice
 * @author Kurt Rinnert
 * @date 2013-07-06
 *
 */


class SDLSoftwareImage : public Image {
public:
    explicit SDLSoftwareImage(RenderDevice *device);
    virtual ~SDLSoftwareImage();
    int getWidth() const;
    int getHeight() const;

    void fillWithColor(const Color& color);
    void drawPixel(int x, int y, const Color& color);
    void drawLine(int x0, int y0, int x1, int y1, const Color& color);
    Image* resize(int width, int height);

    SDL_Surface *surface;

private:
    Uint32 MapRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};

class SDLSoftwareRenderDevice : public RenderDevice {
public:

    SDLSoftwareRenderDevice();

    virtual int render(Renderable& r, Rect& dest);
    virtual int render(Sprite* r);
    virtual int renderToImage(Image* src_image, Rect& src, Image* dest_image, Rect& dest);

    Image* renderTextToImage(FontStyle* font_style, const std::string& text, const Color& color, bool blended);
    void drawPixel(int x, int y, const Color& color);
    void drawLine(int x0, int y0, int x1, int y1, const Color& color);
    void drawRectangle(const Point& p0, const Point& p1, const Color& color);
    void blankScreen();
    void commitFrame();
    void destroyContext();
    void windowResize();
    void setBackgroundColor(Color color);
    void setFullscreen(bool enable_fullscreen);
    Image *createImage(int width, int height);
    void setGamma(float g);
    void resetGamma();
    void updateTitleBar();

    Image* loadImage(const std::string& filename, int error_type);

protected:
    int createContextInternal();
    void createContextError();

private:
    Uint32 MapRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void getWindowSize(short unsigned *screen_w, short unsigned *screen_h);
    void setSDL_RGBA(Uint32 *rmask, Uint32 *gmask, Uint32 *bmask, Uint32 *amask);

    SDL_Surface* screen;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Surface* titlebar_icon;
    char* title;
    uint32_t background_color;
};


#endif // SDLSOFTWARERENDERDEVICE_H
