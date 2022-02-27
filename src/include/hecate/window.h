class Window {
    private:
        const std::string c_AppName = "HecateGIT";
        int m_Width;
        int m_Height;
        bool m_isStarted;
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        SDL_Color m_RenderColor;
        
    public:
        Window();
        ~Window();

        // TODO Add more window create options
        // TODO Read configs from a file (start app + during runtime)
        Window* Size(int width, int height);
        Window* BaseColor(int r, int g, int b, int a);

        void CreateWindow();
        void Start();
        void Quit();
};