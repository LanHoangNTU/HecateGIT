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
        Window* Size(int width, int height);

        void CreateWindow();
        void Start();
        void Quit();
};