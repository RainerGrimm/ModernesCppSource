// cached_computation.cpp

std::mutex m_x;
std::mutex m_result;
double cached_computation(double x){                // (1)
    static double cached_x = 0.0;
	static double cached_result = COMPUTATION_OF_ZERO;
	
    double result;
	{
	    std::scoped_lock(m_x, m_result);
        if (cached_x == x) return cached_result;
	}
    result = computation(x);
	{
	    std::lock_guard<std::mutex> lck(m_x);
        cached_x = x;
	}
	{ 
	    std::lock_guard<std::mutex> lck(m_result);  
        cached_result = result;
	}
    return result;
}

std::mutex m;
double cached_computation(double x){                // (2)
	static double cached_x = 0.0;
	static double cached_result = COMPUTATION_OF_ZERO;
	double result;
    {
        std::lock_guard<std::mutex> lck(m);
		if (cached_x == x) return cached_result;
		result = computation(x);
		cached_x = x;
		cached_result = result;
    }
	return result;
}

std::mutex cachedComputationMutex;                  // (3)
{
    std::lock_guard<std::mutex> lck(cachedComputationMutex);
	auto cached = cached_computation(3.33);
}


double cached_computation(double x){                // (4)
    thread_local double cached_x = 0.0;
    thread_local double cached_result = COMPUTATION_OF_ZERO;
    double result;

    if (cached_x == x) return cached_result;
    result = computation(x);
    cached_x = x;
    cached_result = result;
    return result;
}