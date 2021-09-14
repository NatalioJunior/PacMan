
//**********************************************************************************/
//CARLOS CAVEIRINHA
// GAMESTART AQUI É DEFINIDO A JANELA E SUA PROPRIEDADES COMO A CENA INICIAL
//**********************************************************************************/

#include "Engine.h"
#include "Resources.h"
#include "Home.h"

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura a janela do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 720);
    engine->window->Color(10, 10, 30);
    engine->window->Title("Carlos Caveirinha");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);

    // configura dispositivo gráfico
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    int status = engine->Start(new Home());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

