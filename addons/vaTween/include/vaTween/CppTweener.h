/*****************

 This port was based in a inital code from Jesus Gollonet, him port Penners easing equations to C/C++:

 http://www.jesusgollonet.com/blog/2007/09/24/penner-easing-cpp/
 http://robertpenner.com/easing/

 I¥m just make a better wrapper a litlle more OOP e put some callbacks like the original Tweener
 (http://code.google.com/p/tweener/)


 wesley.marques@gmail.com  - Wesley Ferreira Marques
 http://codevein.com


 **********************/

#ifndef _CPP_TWEEEN_
#define _CPP_TWEEEN_

#include <math.h>
#include <list>
#include <vector>
#include <iostream>


namespace vaTween {


const double PI = 3.1415926535897932384626433832795;


    class Easing {
	public:
		Easing() {

		}
		//pure virtual
		virtual float easeIn(float t,float b , float c, float d)=0;
		virtual float easeOut(float t,float b , float c, float d)=0;
		virtual float easeInOut(float t,float b , float c, float d)=0;

    };

    class Back : public Easing{

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };

    class Bounce : public Easing{

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };

	class Circ : public Easing{

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };

    class Cubic : public Easing{

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };

    class Elastic : public Easing{

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };

    class Expo : public Easing{

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };

    class Quad : public Easing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };


    class Quart : public Easing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };

    class Quint : public Easing {
        public :
		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };

    class Sine : public Easing {
        public :
		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };

    class Linear : public Easing {
        public :
		float easeNone(float t,float b , float c, float d);
		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
    };


    enum {
        LINEAR,
        SINE,
        QUINT,
        QUART,
        QUAD,
        EXPO,
        ELASTIC,
        CUBIC,
        CIRC,
        BOUNCE,
        BACK

    };

    enum {
        EASE_IN,
        EASE_OUT,
        EASE_IN_OUT
	};



    static Linear fLinear;
    static Sine fSine;
    static Quint fQuint;
    static Quart fQuart;
    static Quad  fQuad;
    static Expo fExpo;
    static Elastic fElastic;
    static Cubic fCubic;
    static Circ fCirc;
    static Bounce fBounce;
    static Back fBack;



	struct TweenerProperty {
		float *ptrValue;
		float finalValue;
		float initialValue;
	};
	class TweenerParam  {



	public:
		std::vector<TweenerProperty>  properties;
		float time;
		short transition;
		short equation;
		float delay;
		float timeCount;
		int total_properties;
		bool useMilliSeconds;
		bool started;
		bool delayFinished;

		TweenerParam() {
			useMilliSeconds = true;
			timeCount = 0;
			started = false;
			delayFinished = true;
            delay = 0;
		}
		~TweenerParam(){
			properties.clear();

		}
		TweenerParam(float ptime,short ptransition = EXPO, short pequation = EASE_OUT, float pdelay = 0) {
			time = ptime;
			transition = ptransition;
			equation = pequation;
			useMilliSeconds = true;
			timeCount = 0;
			started = false;
			delayFinished = (pdelay > 0)?false:true;
			delay = pdelay;
		}

		void addProperty(float *valor, float valorFinal) {
			TweenerProperty prop = {valor, valorFinal, *valor};
			properties.push_back(prop);
			total_properties = properties.size();
		}

		void setUseMilliSeconds(bool use ){
			useMilliSeconds = use;
		}

		void cleanProperties(){
			properties.clear();
			std::cout<<"\n-Parameter removed";
		}

		bool operator==( const TweenerParam& p ) {
			bool equal = false;
			if ((time == p.time) && (transition == p.transition) && (equation == p.equation) ){
				equal = true;
			}
			if (equal) {
				for (unsigned int i =0 ; i < p.total_properties; i++ ) {
					if( properties[i].initialValue != p.properties[i].initialValue ||
					   properties[i].finalValue != p.properties[i].finalValue) {
						equal = false;
						break;
					}
				}
			}
			return equal;
		}

	};
	class TweenerListener {
	public:
		TweenerListener(){};
		~TweenerListener(){};
		virtual void onStart(TweenerParam& param) = 0;
		virtual void onStep(TweenerParam& param) = 0 ;
		virtual void onComplete(TweenerParam& param) = 0 ;
		bool operator==( const TweenerListener& l ) {
			return (this == &l) ;
		};
    };


	class Tweener {
        protected :
		enum {ON_START, ON_STEP, ON_COMPLETE};
		short currentFunction ;
		Easing *funcs[11];
		long lastTime;

		std::list<TweenerParam> tweens;
		std::list<TweenerParam>::iterator tweensIT;
		std::list<TweenerListener*> listeners;
		std::list<TweenerListener*>::iterator listenerIT;
		int total_tweens ;

		float runEquation(int transition,int equation, float t,float b , float c, float d);
		void dispatchEvent(TweenerParam *param, short eventType);

	public:
		Tweener() {
			this->funcs[LINEAR] = &fLinear;
			this->funcs[SINE]  = &fSine;
			this->funcs[QUINT] = &fQuint;
			this->funcs[QUART] = &fQuart;
			this->funcs[QUAD] = &fQuad;
			this->funcs[EXPO] = &fExpo;
			this->funcs[ELASTIC] = &fElastic;
			this->funcs[CUBIC] = &fCubic;
			this->funcs[CIRC] =  &fCirc;
			this->funcs[BOUNCE] =  &fBounce;
			this->funcs[BACK] =  &fBack;
		}
		void addTween(TweenerParam& param);
		void removeTween(TweenerParam  *param);
		void addListener(TweenerListener *listener) ;
		void removeListener(TweenerListener *listener) ;
		void setFunction(short funcEnum);
		void step(long currentMillis) ;


    };

}

#endif