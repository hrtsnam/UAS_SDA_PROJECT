#include "scene_6.hpp"
#include <iostream>

void Scene6_PindahScene(Scene *scene)
{
    std:: cout << "Pindah scene\n";
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::Fade);
}

//pilihan 1
void Scene6_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih\n";
    SceneManager_SetBackground(scene->sceneManager, "background/lorong.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Yono",
        "Hey, apakah kau baik-baik saja?"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/talkingUnknow.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "???",
            ". . . Mereka tanya siapa yang menang lomba makan bayangan. . . ");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/talkingUnknow.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Pop},
            },
            {},
            "???",
            "Aku. . .  aku menjawab. . .  bayangan sendiri. . . ");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/talkingUnknow.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Shake},
            },
            {},
            "???",
            "Tapi mereka. . .  hanya tertawa. . .  dan memberi aku bunga plastik. . . ");            
            
     SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Yono",
        "Ah. . .  Obrolan macam apa itu?");

     SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Pop},
        },
        {},
        "Yono",
        "Oke. . .  Tapi maaf, aku harus pergi.",
    Scene6_PindahScene, scene);    
}

void Scene6_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih\n";
    SceneManager_SetBackground(scene->sceneManager, "background/lorong.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/defaultWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide
            },
        },
        {},
        "Yono",
        "Fokus. Fokus. Aku harus siap-siap untuk interviewnya.",
    Scene6_PindahScene, scene);
}

void Scene6_Start(Scene *scene)
{
    Scene6Data *data = (Scene6Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/lorong.png");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson {
                .imageFilePath = "figuran/raw 3.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide
            }
        },
        {},
        "",
        ""
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson {
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide
            }
        },
        {},
        "Yono",
        "Hah . . . siapa itu"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson {
                .imageFilePath = "figuran/talkingUnknow.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide
            }
        },
        {},
        "???",
        "Haaaahhhhhh. . ."
    );


    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {
            DialogQuestion{
                .question = "Bertanya",
                .onAnswered = Scene6_DialogPilihan1,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Hiraukan",
                .onAnswered = Scene6_DialogPilihan2,
                .onAnsweredParameter = scene}
            },
            "Yono",
            "Kenapa ya dia?");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene6_Update(Scene *scene)
{
    // Scene6Data *data = (Scene6Data *)scene->data;
}

void Scene6_Destroy(Scene *scene)
{
}

Scene *Scene6_Create()
{
    Scene6Data *mainMenu = new Scene6Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene6_Start,
        .update = Scene6_Update,
        .destroy = Scene6_Destroy
    };
    return scene;
}
