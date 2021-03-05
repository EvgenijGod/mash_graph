#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"

#include <iostream>
#include <algorithm>

Image::Image(const std::string &a_path, Position start, Position end, bool rotate): rotate(rotate) {
    if ((data = (Pixel *) stbi_load(a_path.c_str(), &width, &height, &channels, 4)) != nullptr) {
        size = width * height * channels;
    }

    if (end == Position{0, 0}) {
        drawable_data = data;
        drawable_width = width;
        drawable_height = height;
    } else {
        this->CutPart(start, end);
        cutted_data = true;
    }
}

Image::Image(int a_width, int a_height, int a_channels) {
    data = new Pixel[a_width * a_height]{};

    if (data != nullptr) {
        width = a_width;
        height = a_height;
        size = a_width * a_height * a_channels;
        channels = a_channels;
        self_allocated = true;
    }
}


int Image::Save(const std::string &a_path) {
    auto extPos = a_path.find_last_of('.');
    if (a_path.substr(extPos, std::string::npos) == ".png" || a_path.substr(extPos, std::string::npos) == ".PNG") {
        stbi_write_png(a_path.c_str(), width, height, channels, data, width * channels);
    } else if (a_path.substr(extPos, std::string::npos) == ".jpg" ||
               a_path.substr(extPos, std::string::npos) == ".JPG" ||
               a_path.substr(extPos, std::string::npos) == ".jpeg" ||
               a_path.substr(extPos, std::string::npos) == ".JPEG") {
        stbi_write_jpg(a_path.c_str(), width, height, channels, data, 100);
    } else {
        std::cerr << "Unknown file extension: " << a_path.substr(extPos, std::string::npos) << "in file name" << a_path
                  << "\n";
        return 1;
    }

    return 0;
}

Image::~Image() {
    if (self_allocated) {
        delete[] data;
        if (cutted_data) {
            delete[] drawable_data;
        }
    }
    else {
        stbi_image_free(data);
    }
}

void Image::CutPart(Position start, Position end) {
    int new_width = end.x - start.x;
    int new_height = end.y - start.y;
    delete []drawable_data;
    Pixel *drawable_part = new Pixel[new_width * new_height]{};
    for (int i = start.y; i < end.y; i++) {
        for (int j = start.x; j < end.x; j++) {
            drawable_part[(i - start.y) * new_width + j - start.x] = data[i * width + j];
        }
    }
    drawable_height = new_height;
    drawable_width = new_width;
    drawable_data = drawable_part;
}
