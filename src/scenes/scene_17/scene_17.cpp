#include "scene_17.hpp"
#include <iostream>


void Scene17_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih ";
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Yono",
        "Ya. Saya penuh rahasia. Berengsel kuat, tapi sering dibuka tanpa izin.");

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
        "Hahaha! Analogi yang bagus");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::None);
}

void Scene17_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih (Balas dengan Guyonan) ";

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/happyWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Yono",
        "Kalau begitu, saya harus buka dan tutup interview ini cepat layaknya pintu.");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[1], SceneTransition::None);
}

void Scene17_DialogPilihan3(Scene *scene)
{
    Scene17Data *data = (Scene17Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");

    std:: cout << "Pilihan 3 dipilih (Berdiri, lalu buat suara 'creak' Pintu) ";

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/happyWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Yono",
        "Krekk... ciiitt... tok!");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[2], SceneTransition::None);
}

void Scene17_Start(Scene *scene)
{
    Scene17Data *data = (Scene17Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
   
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
           {DialogQuestion{
                .question = "Jawab Serius",
                .onAnswered = Scene17_DialogPilihan1,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Balas dengan Guyonan",
                .onAnswered = Scene17_DialogPilihan2,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Berdiri dan Tiru suara pintu",
                .onAnswered = Scene17_DialogPilihan3,
                .onAnsweredParameter = scene}},
        "Mr. Katak",
        "Hahahaha!.. Reinkarnasi lemari 90-an? Unik juga.");
        

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene17_Update(Scene *scene)
{
    Scene17Data *data = (Scene17Data *)scene->data;
}

void Scene17_Destroy(Scene *scene)
{
}

Scene *Scene17_Create()
{
    Scene17Data *mainMenu = new Scene17Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene17_Start,
        .update = Scene17_Update,
        .destroy = Scene17_Destroy
    };
    return scene;
}
