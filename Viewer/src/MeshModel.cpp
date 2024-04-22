#include "MeshModel.h"
#include "Utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <glm/gtc/matrix_transform.hpp>

MeshModel::MeshModel(std::vector<Face> faces, std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> textureCoords, const std::string& modelName) :
	modelTransform(1),
	worldTransform(1),
	modelName(modelName)
{
	worldTransform = glm::mat4x4(1);
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0, 1);
	color = glm::vec3(dist(mt), dist(mt), dist(mt));

	modelVertices.reserve(3 * faces.size());
	for (int i = 0; i < faces.size(); i++)
	{
		Face currentFace = faces.at(i);
		for (int j = 0; j < 3; j++)
		{
			int vertexIndex = currentFace.GetVertexIndex(j) - 1;
			
			Vertex vertex;
			vertex.position = vertices[vertexIndex];
			vertex.normal = normals[vertexIndex];

			if (textureCoords.size() > 0)
			{
				int textureCoordsIndex = currentFace.GetTextureIndex(j) - 1;
				vertex.textureCoords = textureCoords[textureCoordsIndex];
			}

			modelVertices.push_back(vertex);
		}
	}

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, modelVertices.size() * sizeof(Vertex), &modelVertices[0], GL_STATIC_DRAW);

	// Vertex Positions
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Normals attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Vertex Texture Coords
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	// unbind to make sure other code does not change it somewhere else
	glBindVertexArray(0);
}

MeshModel::~MeshModel()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

const glm::vec3& MeshModel::GetColor() const
{
	return color;
}

void MeshModel::SetColor(const glm::vec3& color)
{
	this->color = color;
}

const std::string& MeshModel::GetModelName()
{
	return modelName;
}

void MeshModel::SetWorldTransformation(const glm::mat4x4& worldTransform)
{
	this->worldTransform = worldTransform;
}

const glm::mat4x4& MeshModel::GetWorldTransformation() const
{
	return worldTransform;
}

void MeshModel::SetModelTransformation(const glm::mat4x4& worldTransform)
{
	this->modelTransform = worldTransform;
}

const glm::mat4x4& MeshModel::GetModelTransformation() const
{
	return modelTransform;
}

void MeshModel::TranslateModel(const glm::vec3& translationVector)
{
	modelTransform = Utils::TranslationMatrix(translationVector) * modelTransform;
}

void MeshModel::TranslateWorld(const glm::vec3& translationVector)
{
	worldTransform = Utils::TranslationMatrix(translationVector) * worldTransform;
}

void MeshModel::RotateXModel(double angle)
{
	modelTransform = Utils::XRotationMatrix(angle) * modelTransform;
}

void MeshModel::RotateYModel(double angle)
{
	modelTransform = Utils::YRotationMatrix(angle) * modelTransform;
}

void MeshModel::RotateZModel(double angle)
{
	modelTransform = Utils::ZRotationMatrix(angle) * modelTransform;
}

void MeshModel::ScaleXModel(double factor)
{
	modelTransform = Utils::XScalingMatrix(factor) * modelTransform;
}

void MeshModel::ScaleYModel(double factor)
{
	modelTransform = Utils::YScalingMatrix(factor) * modelTransform;
}

void MeshModel::ScaleZModel(double factor)
{
	modelTransform = Utils::ZScalingMatrix(factor) * modelTransform;
}

void MeshModel::ScaleModel(double factor)
{
	modelTransform = glm::scale(glm::mat4(1), glm::vec3(factor, factor, factor)) * modelTransform;
}

void MeshModel::RotateXWorld(double angle)
{
	worldTransform = Utils::XRotationMatrix(angle) * worldTransform;
}

void MeshModel::RotateYWorld(double angle)
{
	worldTransform = Utils::YRotationMatrix(angle) * worldTransform;
}

void MeshModel::RotateZWorld(double angle)
{
	worldTransform = Utils::ZRotationMatrix(angle) * worldTransform;
}

void MeshModel::ScaleXWorld(double factor)
{
	worldTransform = Utils::XScalingMatrix(factor) * worldTransform;
}

void MeshModel::ScaleYWorld(double factor)
{
	worldTransform = Utils::YScalingMatrix(factor) * worldTransform;
}

void MeshModel::ScaleZWorld(double factor)
{
	worldTransform = Utils::ZScalingMatrix(factor) * worldTransform;
}

void MeshModel::ScaleWorld(double factor)
{
	worldTransform = glm::scale(glm::mat4(1), glm::vec3(factor, factor, factor)) * worldTransform;
}

GLuint MeshModel::GetVAO() const
{
	return vao;
}

const std::vector<Vertex>& MeshModel::GetModelVertices()
{
	return modelVertices;
}