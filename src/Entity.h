#pragma once
#include <bitset>
#include <cstddef>
#include <vector>
#include "Shader.h"
#define MAX_COMPONENTS 512
#define MAX_ENTITIES   512

class IRender_Object
{
  public:
    std::vector<float> vertices;

    Shader *shader;

    virtual void render()
    {
        shader->setActive();
        return;
    }

    void setShader(Shader *shader)
    {
        this->shader = shader;
    }
};

class IUpdate_Object
{
  public:
    virtual void update()
    {
        return;
    }
};

struct Physics
{
    float x, y, z;
};

typedef std::bitset<MAX_COMPONENTS> Component_Mask;
typedef unsigned long long          EntityID;
typedef unsigned long long          PoolID;

struct Entity
{
    EntityID       ID;
    Component_Mask bitmask; // The components that this entity has
};

struct Component_Pool
{
    char  *pData{nullptr};
    size_t elementSize;

    Component_Pool(size_t elementSize)
    {
        pData             = new char[elementSize * MAX_ENTITIES];
        this->elementSize = elementSize;
    }

    ~Component_Pool()
    {
        delete[] pData;
    }

    inline void *get(size_t entityIndex)
    {
        return pData + entityIndex * elementSize;
    }
};

class Scene
{
  private:
    std::vector<Entity> entities;
    // A list containing every type of component lists
    std::vector<Component_Pool *> component_pools;

    int s_componentCounter = 0;

  public:
    Scene()
    {
    }

    EntityID newEntity()
    {
        EntityID ID = entities.size();
        entities.push_back({ID, Component_Mask()});
        return ID;
    }

    // Assign a component with a given entity ID in a component pool
    template <typename T> T *Assign(EntityID ID)
    {
        int componentID = getComponentID<T>();

        // Check if there is enough space for the creation of a new pool
        if (ID >= component_pools.size())
        {
            component_pools.resize(componentID + 1, nullptr);
        }

        // Create the pool if it doesn't exist
        if (component_pools[componentID] == nullptr)
        {
            component_pools[componentID] = new Component_Pool(sizeof(T));
        }

        // Initialize the component
        T *component_ptr = new (component_pools[componentID]->get(ID)) T();

        // Enable the component in the bitmask
        entities[ID].bitmask.set(componentID);
        return component_ptr;
    }

    // Get the specified component associated with the given entity ID
    template <typename T> T *getComponent(EntityID entityID)
    {
        int componentID = getComponentID<T>();

        // Check if the entity has the component
        if (!entities[entityID].bitmask.test(componentID))
        {
            return nullptr;
        }

        // Retrieve a pointer to the component associated with the entity ID
        T *component_ptr = static_cast<T *>(component_pools[componentID]->get(entityID));
        return component_ptr;
    }

    // Get the id of the type or create the id if it does not exist
    template <class T> int getComponentID()
    {
        static int s_componentID = s_componentCounter++;
        return s_componentID;
    }
};