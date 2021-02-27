#include <Engine.h>

class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		// NG_INFO("ExampleLayer::Update");
		if (Engine::Input::IsKeyPressed(NG_KEY_TAB))
			NG_TRACE("Tab pressed!");
	}

	void OnEvent(Engine::Event& event) override
	{
		// NG_TRACE("{0}", event);
	}
};

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Engine::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Engine::Application* Engine::CreateApplication()
{
	return new Sandbox();
}