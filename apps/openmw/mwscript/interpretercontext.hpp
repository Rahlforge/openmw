#ifndef GAME_SCRIPT_INTERPRETERCONTEXT_H
#define GAME_SCRIPT_INTERPRETERCONTEXT_H

#include <components/interpreter/context.hpp>

#include "../mwworld/ptr.hpp"

namespace MWWorld
{
    class World;
}

namespace MWSound
{
    class SoundManager;
}

namespace MWScript
{
    struct Locals;

    class InterpreterContext : public Interpreter::Context
    {
            MWWorld::World& mWorld;
            MWSound::SoundManager& mSoundManager;
            Locals *mLocals;
            MWWorld::Ptr mReference;
        
        public:
        
            InterpreterContext (MWWorld::World& world, MWSound::SoundManager& soundManager,
                MWScript::Locals *locals, MWWorld::Ptr reference);
            ///< The ownership of \a locals is not transferred. 0-pointer allowed.
    
            virtual int getLocalShort (int index) const;

            virtual int getLocalLong (int index) const;

            virtual float getLocalFloat (int index) const;

            virtual void setLocalShort (int index, int value); 

            virtual void setLocalLong (int index, int value);

            virtual void setLocalFloat (int index, float value);
            
            virtual void messageBox (const std::string& message,
                const std::vector<std::string>& buttons);   

            MWWorld::World& getWorld();
            
            MWSound::SoundManager& getSoundManager();
            
            MWWorld::Ptr getReference();
            ///< Reference, that the script is running from (can be empty)
    };
}

#endif

