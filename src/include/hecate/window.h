class Window {
    private:
        int m_Width;
        int m_Height;
        bool m_isStarted;
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        
    public:
        Window();
        ~Window();

        // TODO Add more window create options
        // TODO Read configs from a file (start app + during runtime)
        Window* Size(int width, int height);

        void CreateWindow();
        void Start();
        void Quit();
};