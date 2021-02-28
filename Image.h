#ifndef MAIN_IMAGE_H
#define MAIN_IMAGE_H

#include <string>
#include "shared.h"


constexpr Pixel backgroundColor{0, 0, 0, 0};

struct Image {
    explicit Image(const std::string &a_path, Position start = {0, 0}, Position end = {0, 0}, bool rotate = true);

    Image(int a_width, int a_height, int a_channels);

    int Save(const std::string &a_path);

    int Width() const { return drawable_width; }

    int Height() const { return drawable_height; }

    int Full_Width() const { return width; }

    int Full_Height() const { return height; }

    int Channels() const { return channels; }

    size_t Size() const { return size; }

    Pixel *Data() { return data; }

    Pixel GetPixel(int x, int y) { return data[width * y + x]; }

    void PutPixel(int x, int y, const Pixel &pix) { data[width * y + x] = pix; }

    void CutPart(Position start, Position end);

    ~Image();

private:
    int width = -1;
    int height = -1;
    int drawable_width{}, drawable_height{};
    int channels = 4;
    size_t size = 0;
    Pixel *data = nullptr, *drawable_data = nullptr;
    bool self_allocated = false, cutted_data = false, rotate = true;
};


#endif //MAIN_IMAGE_H
