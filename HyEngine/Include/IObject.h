#pragma once

__interface IBaseRoutine
{
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
};
__interface IRenderable
{
	virtual void Render() = 0;
};
__interface IObject
{
	virtual void Initialize() = 0;
};



