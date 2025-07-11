#pragma once

template <typename T>
void move_vectors(std::vector<T>& source, std::vector<T>& result) {
	if (&source == &result)
		return;
	result = std::move(source);
}