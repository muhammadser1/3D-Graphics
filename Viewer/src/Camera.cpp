#include "Camera.h"
#include "Utils.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up, const float aspectRatio) :
	zoom(1.0f),
	fovy(glm::pi<float>() / 4.0f),
	height(5),
	zNear(0.1f),
	zFar(200.0f),
	aspectRatio(aspectRatio),
	prespective(true),
	viewTransformation(1),
	eye(eye),
	at(at),
	up(up)
{
	UpdateProjectionMatrix();
	viewTransformation = glm::lookAt(eye, at, up);
}

Camera::~Camera()
{
}

//void Camera::SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up)
//{
//	this->eye = eye;
//	this->at = at;
//	this->up = up;
//
//	f = glm::normalize(eye - at);
//	l = glm::normalize(glm::cross(up, f));
//	u = glm::cross(f, l);
//	
//	cameraRotation[0] = glm::vec4(l, 0);
//	cameraRotation[1] = glm::vec4(u, 0);
//	cameraRotation[2] = glm::vec4(f, 0);
//	cameraRotation[3] = glm::vec4(0, 0, 0, 1);
//
//	glm::mat4x4 cameraModelRotation;
//	cameraModelRotation[0] = glm::vec4(-l, 0);
//	cameraModelRotation[1] = glm::vec4(u, 0);
//	cameraModelRotation[2] = glm::vec4(-f, 0);
//	cameraModelRotation[3] = glm::vec4(0, 0, 0, 1);
//
//	cameraInverseRotation = glm::transpose(cameraRotation);
//	cameraTranslation = Utils::TranslationMatrix(eye);
//	cameraInverseTranslation = Utils::TranslationMatrix(-eye);
//	cameraTransformation = cameraInverseRotation * cameraInverseTranslation;
//	worldTransform = cameraTranslation * cameraModelRotation * Utils::ScalingMatrix(glm::vec3(0.2,0.2,0.2));
//}

void Camera::SetOrthographicProjection(
	const float height,
	const float aspectRatio,
	const float zNear,
	const float zFar)
{
	prespective = false;
	float width = aspectRatio * height;
	projectionTransformation = glm::ortho(-width / 2, width / 2, -height / 2, height / 2, zNear, zFar);
}

void Camera::SetPerspectiveProjection(
	const float fovy,
	const float aspectRatio,
	const float zNear,
	const float zFar)
{
	prespective = true;
	projectionTransformation = glm::perspective(fovy, aspectRatio, zNear, zFar);
}

const glm::mat4x4& Camera::GetProjectionTransformation() const
{
	return projectionTransformation;
}

const glm::mat4x4& Camera::GetViewTransformation() const
{
	return viewTransformation;
}

void Camera::Zoom(const float factor)
{
	fovy = fovy * factor;
	if (fovy > glm::pi<float>())
	{
		fovy = glm::pi<float>();
	}

	UpdateProjectionMatrix();
}

void Camera::SphericalRotate(const glm::vec2& sphericalDelta)
{
	//glm::mat4x4 vAxisRotation = Utils::AxisRotationMatrix(u, sphericalDelta.x);
	//glm::mat4x4 uAxisRotation = Utils::AxisRotationMatrix(l, sphericalDelta.y);
	//eye = uAxisRotation * vAxisRotation * glm::vec4(eye,1);
	//SetCameraLookAt(eye, at, glm::vec3(0, 1, 0));
}

void Camera::SetAspectRatio(float aspectRatio)
{
	this->aspectRatio = aspectRatio;
	UpdateProjectionMatrix();
}

void Camera::UpdateProjectionMatrix()
{
	if (prespective)
	{
		SetPerspectiveProjection(fovy, aspectRatio, zNear, zFar);
	}
	else
	{
		SetOrthographicProjection(height, aspectRatio, zNear, zFar);
	}
}

void Camera::SwitchToPrespective()
{
	prespective = true;
	UpdateProjectionMatrix();
}

void Camera::SwitchToOrthographic()
{
	prespective = false;
	UpdateProjectionMatrix();
}

void Camera::SetNear(const float zNear)
{
	this->zNear = zNear;
	UpdateProjectionMatrix();
}

void Camera::SetFar(const float zFar)
{
	this->zFar = zFar;
	UpdateProjectionMatrix();
}

void Camera::SetHeight(const float height)
{
	this->height = height;
	UpdateProjectionMatrix();
}

void Camera::SetFovy(const float fovy)
{
	this->fovy = fovy;
	UpdateProjectionMatrix();
}

float Camera::GetNear()
{
	return zNear;
}

float Camera::GetFar()
{
	return zFar;
}

float Camera::GetFovy()
{
	return fovy;
}

float Camera::GetHeight()
{
	return height;
}

bool Camera::IsPrespective()
{
	return prespective;
}

const glm::vec3& Camera::GetEye() const
{
	return eye;
}