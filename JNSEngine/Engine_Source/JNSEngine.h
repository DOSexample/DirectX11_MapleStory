#pragma once
#include <string>
#include <Windows.h>
#include <assert.h>

#include <vector> // �迭
#include <list> //��ũ�帮��Ʈ 
#include <map> // 2��Ʈ��
#include <bitset> // ��Ʈ �迭 ���ϰ� ������ִ� ���̺귯��
#include <set> // �ؽ� ���̺�
#include <functional> // �Լ� ������

#include <cmath> //����
#include <algorithm> //���� �˰���
#include <limits> //�ε� �Ҽ��� ǥ�� �� �ݿø��� ���õ� Ŭ���� ���ø� numeric_limits �� �� ���� �������� �����մϴ�.
#include <memory> //�޸� ���õ� ���̺귯��
#include <filesystem> // ��������� ���ϰ� �����ִ� ���̺귯��
#include <wrl.h>

#include "CommonInclude.h"
#include "jnsEnums.h"
#include "jnsMath.h"


#define LOAD_TEXTURE(textureName, texturePath, textureVar) \
    std::shared_ptr<Texture> textureVar = Resources::Load<Texture>(textureName, texturePath)

#define SET_MATERIAL(spriteMaterialVar, textureVar) \
    std::shared_ptr<Material> spriteMaterialVar = std::make_shared<Material>(); \
    spriteMaterialVar->SetShader(spriteShader); \
    spriteMaterialVar->SetTexture(textureVar)

#define INSERT_MATERIAL(textureName, spriteMaterialVar) \
    Resources::Insert(textureName, spriteMaterialVar)