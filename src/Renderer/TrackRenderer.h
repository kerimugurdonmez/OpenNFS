#pragma once

#include "../Camera/Camera.h"
#include "../Scene/GlobalLight.h"
#include "../Shaders/TrackShader.h"
#include "../Shaders/BillboardShader.h"
#include "../Loaders/TrackLoader.h"
#include "../RaceNet/Agents/CarAgent.h"
#include "../Config.h"

class TrackRenderer {
public:
    explicit TrackRenderer() = default;
    ~TrackRenderer();
    void Render(const std::vector<std::shared_ptr<CarAgent>> &racers, const std::shared_ptr<Camera> &camera, const GlobalLight &light,  GLuint trackTextureArrayID, const std::vector<std::shared_ptr<Entity>> &visibleEntities, const ParamData &userParams, GLuint depthTextureID, float ambientFactor);
    void RenderLights(const std::shared_ptr<Camera> &camera, const shared_ptr<ONFSTrack> &track);

private:
    // Create and compile our GLSL programs from the shaders
    TrackShader m_trackShader;
    BillboardShader m_billboardShader;
};

