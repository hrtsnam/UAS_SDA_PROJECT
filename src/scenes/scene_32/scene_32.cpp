#include "scene_32.hpp"
#include <iostream>

void Scene32_DialogScene32(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene32 = Scene32_Create();
    // // SceneManager_GoToScene(scene->sceneManager, scene32);
}

void Scene32_PindahScene(Scene *scene)
{
    std::cout << "ENDING C TERBUKAAA\n";
    
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::Fade);

    // SceneManager_PlaySound(scene->sceneManager, "Crowd Laugh.wav");

}

void playApplauseSFX_Scene32(Scene *scene) {
    SceneManager_PlaySound(scene->sceneManager, "Applause.mp3");
}

void Scene32_Start(Scene *scene)
{
    Scene32Data *data = (Scene32Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Dr. Badut",
        "Luar biasa. Irama ternak digital modern.", playApplauseSFX_Scene32, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Mr. Katak",
        "Kamu cocok untuk posisi DJ Kambing.", Scene32_PindahScene, scene);
    // SceneManager_AddDialog(scene->sceneManager, true, "MC", "Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene32_DialogScene32, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene32_Update(Scene *scene)
{
    Scene32Data *data = (Scene32Data *)scene->data;
}

void Scene32_Destroy(Scene *scene)
{
}

Scene *Scene32_Create()
{
    Scene32Data *mainMenu = new Scene32Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene32_Start,
        .update = Scene32_Update,
        .destroy = Scene32_Destroy
    };
    return scene;
}