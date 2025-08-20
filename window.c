// 1. Incluir o cabeçalho principal do Windows
#include <windows.h>

// 2. Protótipo da Função de Janela (Window Procedure)
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// 3. Ponto de Entrada Principal: WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 4. Definir o nome da classe da janela
    const char CLASS_NAME[] = "MinhaClasseDeJanela";

    // 5. Registrar a classe da janela
    WNDCLASS wc = { }; // Inicializa a estrutura com zeros

    wc.lpfnWndProc   = WindowProc;             // Ponteiro para a função que processa mensagens
    wc.hInstance     = hInstance;              // "Handle" para a instância da aplicação
    wc.lpszClassName = CLASS_NAME;            // Nome da classe
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW); // Define o cursor padrão
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Define a cor de fundo

    RegisterClass(&wc);

    // 6. Criar a janela
    HWND hwnd = CreateWindowEx(
        0,                              // Estilos estendidos opcionais
        CLASS_NAME,                     // Nome da classe da janela
        "Janela",  // Título da janela
        WS_OVERLAPPEDWINDOW,            // Estilo da janela (padrão, com botões de minimizar, maximizar, fechar)

        // Posição e tamanho
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,

        NULL,       // Janela pai (NULL para janela principal)
        NULL,       // Menu (NULL para nenhum menu)
        hInstance,  // "Handle" da instância da aplicação
        NULL        // Dados adicionais (não usados aqui)
    );

    // 7. Verificar se a janela foi criada com sucesso
    if (hwnd == NULL) {
        return 0;
    }

    // 8. Mostrar a janela na tela
    ShowWindow(hwnd, nCmdShow);

    // 9. O Loop de Mensagens (Message Loop)
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// 10. Implementação da Função de Janela (Window Procedure)
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);

                // Aqui é onde você desenharia na janela.
                // Por enquanto, vamos apenas preencher o fundo.
                FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

                EndPaint(hwnd, &ps);
            }
            return 0;
    }
    // 11. Deixar o Windows lidar com mensagens que não tratamos
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
