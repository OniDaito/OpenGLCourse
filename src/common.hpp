/**
* @brief Common Headers that are external
* @file common.hpp
* @author Benjamin Blundell <oni@section9.co.uk>
* @date 06/07/2012
*
*/


///\todo precompile!

#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fstream>

#include <stdint.h> 
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>
#include <boost/function.hpp>
#include <boost/assign/std/vector.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/ptr_container/ptr_deque.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <boost/shared_ptr.hpp>


#define GLM_SWIZZLE 
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/swizzle.hpp>
#include <glm/gtc/swizzle.hpp>
#include <glm/gtx/matrix_interpolation.hpp>

#include <GL/glew.h>
#include <GL/glut.h>

#include "glutils.hpp"


#endif
