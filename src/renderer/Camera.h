#ifndef SG_BROWSER_CAMERA_H
#define SG_BROWSER_CAMERA_H

#include <glm/glm.hpp>

namespace SG {
    struct Camera {
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.3f);
        glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 right;
        
        float movementSpeed;
        float mouseSensitivity;
        float zoom;
    };
}


#endif //SG_BROWSER_CAMERA_H
