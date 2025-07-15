# Idea for basic browser flow

- Startup is pretty self explanatory, initialize layers and start main loop,
- ImGuiLayer dispatches action `UrlSearchAction`,
- Startup REST Client,
- Make the GET call,
- Start parsing index.html,
- Find all the `src` tags and get other HTML, JS and CSS files,
- Parse everything and connect,
- Build DOM,
- Send Event/DOM handle to `RendererLayer`,
- Render using OpenGL

## Notes

- Start with single `index.html` with some `script` and `styles`