#pragma once

template <typename T>
void move_vectors(std::vector<T>& source, std::vector<T>& dest) {
	if (&source != &dest)
		dest = std::move(source);
}