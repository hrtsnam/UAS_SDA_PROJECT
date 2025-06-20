#include "scene4_part2.hpp"
#include <iostream>

//pilihan 1
void Scene4Part2_DialogPilihan1(Scene *scene)
{
    std::cout << "Pilihan 1 dipilih\n";
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::Fade);
}

//pilihan 2
void Scene4Part2_DialogPilihan2(Scene *scene)
{
    std::cout << "Pilihan 2 dipilih\n";
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[1], SceneTransition::Fade);
}

void Scene4Part2_Start(Scene *scene)
{
    Scene4Part2Data *data = (Scene4Part2Data *)scene->data;
    
    SceneManager_SetBackground(scene->sceneManager, "background/lift.png");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/toav2.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide
            }
        },
        {},
        "Speaker Unit",
        "Selamat datang di Absurdia Inc.!"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/toav2.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None
            }
        },
        {},
        "Speaker Unit",
        "Silahkan nikmati musik kami yang autentik. . ."
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide
            }
        },
        {},
        "Yono",
        "Ah. . . lagu apa ini. . ."
    );
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None
            }
        },
        {},
        "Yono",
        "Sudahlah, sebenarnya ini cukup lucu"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
            },
            {
                DialogQuestion{
                    .question = "Naik",
                    .onAnswered = Scene4Part2_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Turun",
                    .onAnswered = Scene4Part2_DialogPilihan2,
                    .onAnsweredParameter = scene}},
        "Yono",
        "Nah, sekarang tinggal ke atas.");
        

    SceneManager_PlayMusic(scene->sceneManager, "newElevator.mp3");
}

void scene4Part2_Update(Scene *scene)
{
    // Scene4Data *data = (Scene4Data *)scene->data;
}

void Scene4Part2_Destroy(Scene *scene)
{
    // Scene4Data *data = (Scene4Data *)scene->data;
    // delete data;
}

Scene *Scene4Part2_Create()
{
    Scene4Part2Data *data = new Scene4Part2Data();
    Scene *scene = new Scene{
        .data = data,
        .start = Scene4Part2_Start,
        .update = scene4Part2_Update,
        .destroy = Scene4Part2_Destroy
    };
    return scene;
}
